#include <iostream>
#include<vector>
#include<algorithm>
#include "conio.h"
#include "snake.hpp"


namespace snake {
    bool gameOver;
    const int width = 20;
    const int height = 20;
    int x, y, fruetX, fruetY, score;

    int tailX[100];
    int tailY[100];
 
    int latensy = 400;
    enum eDirection 
    {
        STOP = 0,
        LEFT = 1,
        RIGHT =2,
        UP = 3,
        DOWN = 4
    };

    eDirection dir;

    void say_hello() 
    {
        std::cout << "Snake: S-s-s-s-s-s-s...." << std::endl;
    }

     void callFruet()
    {
        fruetX = rand() % (width-1);
        fruetY = rand() % (height-2);
    }

    void Setup()
    {
        srand(time(0));
        gameOver = false;
        dir = STOP;
        x = width / 2;
        y = height / 2;
        score = 0;
        callFruet();
    }

    void Drow()
    {
        system("cls"); // clear

        for(int i = 0; i < width+1; i++) // top line
            std::cout <<"#";
        std::cout<<std::endl;

        for(int i = 0; i < width; i++)
        {
            for(int j = 0; j < height; j++)
            {
                if (j == 0 || j == width-1)
                    std::cout << "#";
                if (i == x && j == y)
                    std::cout << "0";
                else if (i == fruetX && j == fruetY)
                    std::cout << "$";
                else { 

                    bool isTail = false;
                    for(int t = 0; t < score; t++)
                    {
                        if(tailX[t] == i && tailY[t] == j)
                        {
                            isTail = true;
                            std::cout<<"o";
                        }
                    }
                    if(!isTail)
                        std::cout<<" ";
                }
            }
            std::cout<<std::endl;
        }

        for(int i = 0; i < width+1; i++) // bottom line
            std::cout <<"#";
        std::cout<<std::endl;

        std::cout<<"SCORE: "<<score<<std::endl;
        std::cout<< "Coordinates X-"<<x<<" Y-"<<y<<std::endl;
    }

    void Input()
    {
        if(_kbhit()) {
            switch (_getch())
            {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
            
            }
        }
    }

    void Logic()
    {
        int prevX = tailX[0];
        int prevY = tailY[0];
        int prev2X, prev2Y;
        tailX[0] = x;
        tailY[0] = y;
        for (int i = 1; i < score; i++)
        {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }
        switch(dir){
        case LEFT:
            y--;
            break;
        case RIGHT:
            y++;
            break;
        case UP:
            x--;
            break;
        case DOWN:
            x++;
            break;
        }

        if(x > width -1)
            x = 0;
        else if(x < 0)
            x = width-1;
        if(y > height-2)
            y = 0;
        else if(y < 0)
            y = height-2;
        
        for(int t = 0; t < score; t++)
        {
            if(tailX[t] == x && tailY[t] == y)
                gameOver = true;
        }

        if(x == fruetX && y == fruetY){
            score++;

            callFruet();
            
            if(0 != latensy)
                latensy -= 10;
        }
    }
}