#include "GameClass.h"
/*
    Requirements:
    [*] Graphic interface
    [] RTTI
    [] Abstract Classes
    [*] Overloaded operators (4 / 4)
    [*] Heap Memory Allocation
    [] Exceptions
    [*] STL
    [*] Lambda expressions in spaceship.cpp
    [*] Templates
    [*] Smart pointers in GameClass.cpp
    [] Desing patterns (1 / 2) in Spaceship.cpp
    [*] Features of C++17 updateObjects in GameClass
*/

Spaceship* Spaceship::instance = nullptr;

int main() 
{
    GameClass game;

    game.run();
   
    return 0;
}