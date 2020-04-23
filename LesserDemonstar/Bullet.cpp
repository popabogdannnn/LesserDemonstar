#include "Bullet.h"

Bullet::Bullet(float _x, float _y, float _speed, sf::Texture _texture): Object(_x, _y, _speed, _texture)
{
	//std::cout << "Creat\n";
	this->damage = 10;
}

Bullet::~Bullet()
{
	//delete &this->damage;
	//std::cout << "Bullet destroyed\n";
}

int Bullet::getDamage()
{
	return this->damage;
}