#ifndef SNAKE_H
#define SNAKE_H
#include <windows.h>
#include <vector>

#define WIDTH 75
#define HEIGHT 35

using namespace std;
 
class Snake{
private:
    COORD pos;
    int len;
    int vel;
    char direction;
    vector<COORD> body;

public:
    Snake (COORD pos, int vel);
    void changeDir(char dir);
    void moveSnake();
    COORD getPos();
    bool eaten( COORD foodPos);
    void grow();
    bool collided();
    vector<COORD> getBody();

};
#endif