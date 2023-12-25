#include "Snake.h"

Snake:: Snake (COORD pos, int vel){
    this->pos=pos;
    this->vel=vel;
    len=1;
    direction= 'n';
    body.push_back(pos);
}

void Snake::changeDir(char dir){
    direction=dir;
}

void Snake::moveSnake(){
    switch (direction){
        case 'u': 
            pos.Y -= vel;
            break;
        case 'd': 
            pos.Y += vel;
            break;
        case 'l': 
            pos.X -= vel;
            break;
        case 'r': 
            pos.X += vel;
            break;
    }

    body.push_back(pos);

    if (body.size() > len){
        body.erase(body.begin());
    }
}

vector<COORD> Snake:: getBody(){
    return body;
}

COORD Snake::getPos(){
    return pos;
} 

bool Snake::eaten( COORD foodPos){
    return (foodPos.X == pos.X && foodPos.Y == pos.Y);
}

void Snake:: grow(){
    len= len+1;
}

bool Snake:: collided(){
    if (pos.X < 1 || pos.X > WIDTH-2 || pos.Y <1 || pos.Y > HEIGHT-2)
        return true;
    
    for (int i=0; i<len-1; i++){
        if (pos.X == body[i].X && pos.Y == body[i].Y)
            return true;
    }

    return false;
}