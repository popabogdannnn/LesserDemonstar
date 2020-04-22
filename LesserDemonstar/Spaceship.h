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
	Spaceship();

public:
	~Spaceship();
	Spaceship* getInstance();

	void updateScore(int);
	void updateHP(int);

	int getScore();
	int getHP();
	float getSpeed();

	void setSpeed(float);
	void setShootingSpeed(int);

	void updateReloadingCooldown();

	Bullet* shoot(sf::Texture);

	bool canShoot();
};
