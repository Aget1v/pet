#include "snake.hpp"
#include<thread>
#include<chrono>
//#include "conio.h"

int main() {
    snake::say_hello();

    snake::Setup();
    while (!snake::gameOver)
    {
        snake::Drow();
        snake::Input();
        snake::Logic();
        std::this_thread::sleep_for(std::chrono::milliseconds(snake::latensy));
    }
    return 0;
}