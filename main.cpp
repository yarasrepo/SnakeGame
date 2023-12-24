#include <iostream>
#include "Snake.h"
#include "Food.h"
#include <conio.h>
#include <ctime>
//https://www.youtube.com/watch?v=AxrQje7V65o&ab_channel=ProgrammingKnowledge 
//1:00:00
#define WIDTH 50
#define HEIGHT 25
using namespace std;

Snake snake({WIDTH/2, HEIGHT/2}, 1);
Food food;

void board(){

    COORD snakePos= snake.getPos();
    COORD foodPos= food.getPos();

    for (int i=0; i< HEIGHT; i++){
        cout << "#";
        for (int j=0; j<WIDTH-2; j++){
            if (i==0 || i== HEIGHT-1)
                cout << '#';
            else if (i==snakePos.Y && j+1==snakePos.X)
                cout << '0';
            else if (i == foodPos.Y && j +1== foodPos.X)
                cout << '*';
            else 
                cout << ' ';
        }
        cout << "#\n";
    }
}

int main(){
    srand(time(NULL));
    food.genFood();
    bool gameOver = false;

    while (!gameOver){
        board();

        if (kbhit()){
            switch(getch()){
                case ' w':
                    snake.changeDir('u');
                    break;
                case ' a':
                    snake.changeDir('l');
                    break;
                case ' s':
                    snake.changeDir('d');
                    break;
                case ' d':
                    snake.changeDir('r');
                    break;
            }
        }
        if (snake.collided()){
                gameOver= true;
            }

            if (snake.eaten(food.getPos())){
                food.genFood();
                snake.grow();
            }

        
        snake.moveSnake();
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0});
    }
    return 0;
}

