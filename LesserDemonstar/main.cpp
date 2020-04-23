#include "GameClass.h"
/*
    Requirements:
    [*] Graphic interface
    [*] RTTI
    [*] Abstract Classes Object class is abstract
    [*] Overloaded operators (4 / 4)
    [*] Heap Memory Allocation
    [] Exceptions in gameclass.cpp in loadingTextures
    [*] STL
    [*] Lambda expressions in spaceship.cpp
    [*] Templates
    [*] Smart pointers in GameClass.cpp
    [] Desing patterns (1 / 2) Singleton in Spaceship.cpp Factory in Object
    [*] Features of C++17 updateObjects in GameClass
*/

Spaceship* Spaceship::instance = nullptr;

int main() 
{
    GameClass game;

    game.run();
   
    return 0;
}