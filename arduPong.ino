#include <Arduboy.h>
#include "ball.h"
Arduboy arduboy;

// Game
int gameState = 0;
int justPressed = 0;
int playerScore = 0;
int computerScore = 0;

// Ball
Ball ball = Ball(62, 0, 4);
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
      arduboy.fillRect(ball.getX(), ball.getY(), ball.getSize(), ball.getSize(), WHITE);
      ball.move();
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
  if(ball.getX() > 115 or rand() % 20 == 1) {
    if(ball.getY() < computerY) {
      computerY--;
    }
    if(ball.getY() + ball.getSize() > computerY + paddleHeight) {
      computerY++;
    }    
  }
}

// Game
void bounce() {
  if(ball.getX() == playerX + paddleWidth and playerY < ball.getY() + ball.getSize() and playerY + paddleHeight > ball.getY()) {
    ball.goToRight();
  }
  if(ball.getX() + ball.getSize() == computerX and computerY < ball.getY() + ball.getSize() and computerY + paddleHeight > ball.getY()) {
    ball.goToLeft();
  }
}

void score() {
  if(ball.getX() < -10) {
    ball.reset();
    computerScore++;
  }
  if(ball.getX() > 130) {
    ball.reset();
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
  ball.reset();
  playerScore = 0;
  computerScore = 0;
}



