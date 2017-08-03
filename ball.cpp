#include "ball.h"

Ball::Ball() {}

Ball::Ball(int x, int y, int size) {
  this->x = x;
  this->y = y;
  this->size = size;
  this->right = 1;
  this->down = 1;
}

void Ball::move() {
  right == 1 ? x++ : x--;
  down == 1 ? y++ : y--;
  if(y == 0) {
    down = 1;
  }
  if(y + size == 63) {
    down = -1;
  }
}

void Ball::goToRight() {
  right = 1;
}

void Ball::goToLeft() {
  right = -1;
}

void Ball::reset() {
  x = 63;
}

int Ball::getX() {
  return x;
}

int Ball::getY() {
  return y;
}

int Ball::getSize() {
  return size;
}
