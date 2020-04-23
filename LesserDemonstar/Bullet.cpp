#include "Bullet.h"

Bullet::Bullet(sf::Texture bulletTexture)
{
	std::cout << "Creat\n";
	this->damage = 10;
	this->speed = -15;
	this->texture = bulletTexture;
	this->xSize = bulletTexture.getSize().x;
	this->ySize = bulletTexture.getSize().y;
}

Bullet::~Bullet()
{
	//delete &this->damage;
	std::cout << "Bullet destroyed\n";
}

int Bullet::getDamage()
{
	return this->damage;
}