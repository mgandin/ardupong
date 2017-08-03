#include "paddle.h"

Paddle::Paddle() {}

Paddle::Paddle(int x, int y, int width, int height) {
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
}

void Paddle::up() {
  y--;
}

void Paddle::down() {
  y++;
}

int Paddle::canGoUp() {
  return y > 0;
}

int Paddle::canGoDown() {
  return y + height < 63;
}

int Paddle::getX() {
  return x;
}

int Paddle::getY() {
  return y;
}

int Paddle::getWidth() {
  return width;
}

int Paddle::getHeight() {
  return height;
}

