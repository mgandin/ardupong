#include "game.h"

Game::Game(Ball *ball, Paddle *player, Paddle *computer) {
  this->ball = ball;
  this->player = player;
  this->computer = computer;
  this->playerScore = 0;
  this->computerScore = 0;
  this->state = 0;
}

void Game::move() {
  if(ball->getX() > 115 or rand() % 20 == 1) {
    if(ball->getY() < computer->getY()) {
      computer->up();
    }
    if(ball->getY() + ball->getSize() > computer->getY() + computer->getHeight()) {
      computer->down();
    }
  }
}

void Game::bounce() {
    if(ball->getX() == player->getX() + player->getWidth() and player->getY() < ball->getY() + ball->getSize() and player->getY() + player->getHeight() > ball->getY()) {
    ball->goToRight();
  }
  if(ball->getX() + ball->getSize() == computer->getX() and computer->getY() < ball->getY() + ball->getSize() and computer->getY() + computer->getHeight() > ball->getY()) {
    ball->goToLeft();
  }
}

void Game::score() {
  if(ball->getX() < -10) {
    ball->reset();
    computerScore++;
  }
  if(ball->getX() > 130) {
    ball->reset();
    playerScore++;
  }
  if(playerScore == 5) {
    state = 2;
  }
  if(computerScore == 5) {
    state = 3;
  }
}

void Game::play() {
  state = 1;
}

void Game::reset() {
  ball->reset();
  playerScore = 0;
  computerScore = 0;
  state = 0;
}

int Game::getState() {
  return state;
}

int Game::getPlayerScore() {
  return playerScore;
}

int Game::getComputerScore() {
  return computerScore;
}

