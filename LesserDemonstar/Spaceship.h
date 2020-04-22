#pragma once
#include "Object.h"
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

	void updateScore(int x);
	void updateHP(int x);

	int getScore();
	int getHP();
	float getSpeed();
	
	void setSpeed(float v);
	void setShootingSpeed(int value); 

	void shoot();
	
	bool canShoot();
};

