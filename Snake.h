#ifndef SNAKE_H
#define SNAKE_H
#include <windows.h>

#define WIDTH 50
#define HEIGHT 25
 
class Snake{
private:
    COORD pos;
    int len;
    int vel;
    char direction;

public:
    Snake (COORD pos, int vel);
    void changeDir(char dir);
    void moveSnake();
    COORD getPos();
    bool eaten( COORD foodPos);
    void grow();
    bool collided();
};
#endif