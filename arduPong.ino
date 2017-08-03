#include <Arduboy.h>
#include "ball.h"
#include "paddle.h"
#include "game.h"
Arduboy arduboy;

int justPressed = 0;

Ball ball = Ball(62, 0, 4);
Paddle player = Paddle(0, 0, 4, 9);
Paddle computer = Paddle(127 - player.getWidth(), 0, 4, 9);
Game game = Game(&ball, &player, &computer);

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
  switch(game.getState()) {
    case 0:
      welcome();
      break;
    case 1:
      play();
      break;
    case 2:
      end("You win !");
      break;
    case 3:
      end("Game Over !");
      break;
  }
  if(arduboy.notPressed(A_BUTTON)) {
    justPressed = 0;
  }
  arduboy.display();
}

void welcome() {
  arduboy.print("Welcome to Ardupong !");
  arduboy.print("\n");
  arduboy.print("Press A to start");

  if(arduboy.pressed(A_BUTTON) and justPressed == 0) {
    justPressed = 1;
    game.play();
  }
}

void play() {
  arduboy.fillRect(ball.getX(), ball.getY(), ball.getSize(), ball.getSize(), WHITE);
  ball.move();
  arduboy.fillRect(player.getX(), player.getY(), player.getWidth(), player.getHeight(), WHITE);
  movePaddle();
  arduboy.fillRect(computer.getX(), computer.getY(), computer.getWidth(), computer.getHeight(), WHITE);
  game.move();
  game.bounce();
  arduboy.setCursor(20, 0);
  arduboy.print(game.getPlayerScore());
  arduboy.setCursor(101, 0);
  arduboy.print(game.getComputerScore());
  game.score();
  handleRestart();
}

void movePaddle() {
  if(arduboy.pressed(UP_BUTTON) and player.canGoUp()) {
    player.up();
  }
  if(arduboy.pressed(DOWN_BUTTON) and player.canGoDown()) {
    player.down();
  }
}

void end(char *msg) {
  arduboy.print(msg);
  handleRestart();
}

void handleRestart() {
  if(arduboy.pressed(A_BUTTON) and justPressed == 0) {
    justPressed = 1;
    game.reset();
  }
}

