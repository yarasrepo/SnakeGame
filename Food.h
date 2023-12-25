#ifndef FOOD_H
#define FOOD_H

#include <windows.h>
#include <cstdlib>

#define WIDTH 75
#define HEIGHT 35

class Food{

private:
    COORD pos;
public:
    void genFood();
    COORD getPos();
};

#endif