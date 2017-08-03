#ifndef COMPUTER_H
#define COMPUTER_H
#include "ball.h"
#include "paddle.h"
#include <Arduboy.h>

class Game {
  private:
    Ball *ball;
    Paddle *player;
    Paddle *computer;
    int playerScore;
    int computerScore;
    int state;
  public:
    Game(Ball *ball, Paddle *player, Paddle *computer);
    void move();
    void bounce();
    void score();
    void reset();
    void play();
    int getState();
    int getPlayerScore();
    int getComputerScore();
};
#endif
