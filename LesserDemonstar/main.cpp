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
    [*] Desing patterns (2 / 2) Singleton in Spaceship.cpp Factory in Object and below
    [*] Features of C++17 updateObjects in GameClass
*/

Spaceship* Spaceship::instance = nullptr;

Object* Object::Create(ObjectType type, float _x, float _y, float _speed, sf::Texture _texture)
{
    if (type == OT_Asteroid) {
        Asteroid* ret = new Asteroid(_x, _y, _speed, _texture);
        return ret;
    }

    if (type == OT_Bullet) {
        Bullet* ret = new Bullet(_x, _y, _speed, _texture);
        return ret;
    }
    return nullptr;
}

int main() 
{
    srand(time(NULL));
    GameClass game;

    game.run();
   
    return 0;
}