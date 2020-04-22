#include "GameClass.h"
/*
    Requirements:
    [*] Graphic interface
    [] RTTI
    [] Abstract Classes
    [] Overloaded operators (0 / 4)
    [*] Heap Memory Allocation
    [] Exceptions
    [] Lambda expressions
    [] Templates
    [*] Smart pointers
    [] Desing patterns (1 / 2)
    [] Features of C++17
*/

Spaceship* Spaceship::instance = nullptr;

int main() 
{
    GameClass game;

    game.run();
   
    return 0;
}