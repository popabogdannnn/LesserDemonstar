#pragma once
#include "Object.h"
#include "Bullet.h"
class Spaceship :
	public Object
{
private:
	static Spaceship* instance;
	int score;
	int HP;
	int shootingSpeed; // shoots every shootingSpeed frames
	int reloadingCooldown;
	Spaceship(float, float, float, sf::Texture);

public:
	~Spaceship();
	Spaceship* getInstance(float, float, float, sf::Texture);

	void updateScore(int);
	void updateHP(int);

	int getScore();
	int getHP();
	float getSpeed();

	void setSpeed(float);
	void setShootingSpeed(int);

	void updateReloadingCooldown();

	void shoot();

	bool canShoot();
};
