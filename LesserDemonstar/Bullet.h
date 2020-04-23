#pragma once
#include "Object.h"
class Bullet :
	public Object
{
private:
	int damage;

public:

	Bullet(float, float, float, sf::Texture);
	~Bullet();

	int getDamage();
};
