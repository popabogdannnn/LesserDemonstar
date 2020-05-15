#include "Asteroid.h"

//public functions

void Asteroid::updateHP(int x)
{
	this->HP += x;
}

int Asteroid::getDamage()
{
	return this->damage;
}

int Asteroid::getHP()
{
	return this->HP;
}

Asteroid::Asteroid(float _x, float _y, float _speed, sf::Texture _texture): Object(_x, _y, _speed, _texture)
{
	this->damage = 20;
	this->HP = 20;
}

Asteroid::~Asteroid()
{
	//std::cout << "Asteroid distrus\n";
}
