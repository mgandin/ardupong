#ifndef PADDLE_H
#define PADDLE_H

class Paddle {
  private :
    int x;
    int y;
    int width;
    int height;
  public :
    Paddle();
    Paddle(int x, int y, int width, int height);
    void up();
    void down();
    int canGoUp();
    int canGoDown();
    int getX();
    int getY();
    int getHeight();
    int getWidth();
};
#endif
