#include "GameClass.h"
/*
    Requirements:
    [*] Graphic interface
    [*] RTTI
    [*] Abstract Classes in Object class is abstract
    [*] Overloaded operators (4 / 4)
    [*] Heap Memory Allocation all over the place
    [*] Exceptions in gameclass.cpp in loadingTextures
    [*] STL in BestVector.h, in Object.h
    [*] Lambda expressions in spaceship.cpp, in GameClass.cpp
    [*] Templates in BestVector.h
    [*] Smart pointers in GameClass.h
    [*] Desing patterns (2 / 2) Singleton in Spaceship.cpp Factory in Object and below
    [*] Features of C++17 updateObjects, updatePlayer in GameClass
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