#pragma once
#include "Object.h"
class Asteroid :
	public Object
{
private:
	int damage;
	int HP;

public:

	void updateHP(int x);
	int getDamage();

	int getHP();

	Asteroid(float, float, float, sf::Texture);
	~Asteroid();
};

