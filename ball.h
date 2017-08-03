#ifndef BALL_H
#define BALL_H

class Ball {
  private:
    int right;
    int down;
    int x;
    int y;
    int size;
  public:
    Ball();
    Ball(int x, int y, int size);
    void move();
    void goToRight();
    void goToLeft();
    void reset();
    int getX();
    int getY();
    int getSize();
};
#endif

