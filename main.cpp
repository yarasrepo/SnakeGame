#include <iostream>
#include <cstdlib>
#include "Snake.h"
#include <conio.h>
//https://www.youtube.com/watch?v=AxrQje7V65o&ab_channel=ProgrammingKnowledge 
//30
#define WIDTH 50
#define HEIGHT 25
using namespace std;

Snake snake({WIDTH/2, HEIGHT/2}, 1);

void board(){

    COORD snakePos= snake.getPos();

    for (int i=0; i< HEIGHT; i++){
        cout << "#";
        for (int j=0; j<WIDTH-2; j++){
            if (i==0 || i== HEIGHT-1)
                cout << '#';
            else if (i==snakePos.Y && j==snakePos.X)
                cout << '0';
            else 
                cout << ' ';
        }
        cout << "#\n";
    }
}

int main(){
    while (true){
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
            snake.moveSnake();
        }
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0});
    }
    return 0;
}

