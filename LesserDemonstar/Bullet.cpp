#include "Bullet.h"

Bullet::Bullet(sf::Texture bulletTexture)
{
	this->damage = 10;
	this->speed = -7.5;
	this->texture = bulletTexture;
	this->xSize = bulletTexture.getSize().x;
	this->ySize = bulletTexture.getSize().y;
}

int Bullet::getDamage()
{
	return this->damage;
}
