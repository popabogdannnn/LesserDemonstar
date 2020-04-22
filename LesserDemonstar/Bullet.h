#pragma once
#include "Object.h"
class Bullet :
	public Object
{
private:
	float damage;

public:

	Bullet(sf::Texture);

	int getDamage();
};
