#include <Arduboy.h>
Arduboy arduboy;

// Game
int gameState = 0;
int justPressed = 0;
int playerScore = 0;
int computerScore = 0;

// Ball
int ballX = 62;
int ballY = 0;
int ballSize = 4;
int ballRight = 1;
int ballDown = 1;

// Paddle
int paddleWidth = 4;
int paddleHeight = 9;
int playerX = 0;
int playerY = 0;

// Computer paddle
int computerX = 127 - paddleWidth;
int computerY = 0;

void setup() {
  arduboy.begin();
  srand(7/8);
  arduboy.setFrameRate(60);
  arduboy.clear();
}

void loop() {
  if(!arduboy.nextFrame()) {
    return;
  }
  arduboy.clear();
  arduboy.setCursor(0, 0);
  switch(gameState) {
    case 0:
      // Title
      arduboy.print("Ardupong");
      if(arduboy.pressed(A_BUTTON) and justPressed == 0) {
        justPressed = 1;
        gameState = 1;
      }
      break;
    case 1:
      // Gameplay
      arduboy.fillRect(ballX, ballY, ballSize, ballSize, WHITE);
      moveBall();
      arduboy.fillRect(playerX, playerY, paddleWidth, paddleHeight, WHITE);
      movePaddle();
      arduboy.fillRect(computerX, computerY, paddleWidth, paddleHeight, WHITE);
      moveComputer();
      bounce();
      arduboy.setCursor(20, 0);
      arduboy.print(playerScore);
      arduboy.setCursor(101, 0);
      arduboy.print(computerScore);
      score();
      if(arduboy.pressed(A_BUTTON) and justPressed == 0) {
        justPressed = 1;
        gameState = 2;
      }
      break;
    case 2:
      // Win
      arduboy.print("You win !");
      if(arduboy.pressed(A_BUTTON) and justPressed == 0) {
        justPressed = 1;
        resetGame();
        gameState = 0;
      }
      break;
    case 3:
      // Game over
      arduboy.print("Game Over !");
      if(arduboy.pressed(A_BUTTON) and justPressed == 0) {
        justPressed = 1;
        resetGame();
        gameState = 0;
      }
      break;
  }
  if(arduboy.notPressed(A_BUTTON)) {
    justPressed = 0;
  }
  arduboy.display();
}

// Ball
void moveBall() {
  ballRight == 1 ? ballX++ : ballX--;
 
  ballDown == 1 ? ballY++ : ballY--;
  if(ballY == 0) {
    ballDown = 1;
  }
  if(ballY + ballSize == 63) {
    ballDown = -1;
  }
}

// Paddle
void movePaddle() {
  if(arduboy.pressed(UP_BUTTON) and playerY > 0) {
    playerY--;
  }
  if(arduboy.pressed(DOWN_BUTTON) and playerY + paddleHeight < 63) {
    playerY++;
  }
}

// Computer Paddle
void moveComputer() {
  if(ballX > 115 or rand() % 20 == 1) {
    if(ballY < computerY) {
      computerY--;
    }
    if(ballY + ballSize > computerY + paddleHeight) {
      computerY++;
    }    
  }
}

// Game
void bounce() {
  if(ballX == playerX + paddleWidth and playerY < ballY + ballSize and playerY + paddleHeight > ballY) {
    ballRight = 1;
  }
  if(ballX + ballSize == computerX and computerY < ballY + ballSize and computerY + paddleHeight > ballY) {
    ballRight = -1;
  }
}

void score() {
  if(ballX < -10) {
    ballX = 63;
    computerScore++;
  }
  if(ballX > 130) {
    ballX = 63;
    playerScore++;
  }
  if(playerScore == 5) {
    gameState = 2;
  }
  if(computerScore == 5) {
    gameState = 3;
  }
}

void resetGame() {
  ballX = 63;
  playerScore = 0;
  computerScore = 0;
}



