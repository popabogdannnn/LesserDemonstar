#include "Spaceship.h"

//private functions

Spaceship::Spaceship()
{
	std::cout << "IM ALIVE\n";
	this -> score = 0;
	this->speed = 2.5;
	this -> HP = 100;
	this->shootingSpeed = 100;
}

//public functions

Spaceship::~Spaceship()
{
	delete this->instance;
	this->instance = nullptr;
}

Spaceship* Spaceship::getInstance()
{
	if (this->instance == nullptr) {
		this->instance = new Spaceship;
	}
	return this->instance;
}

void Spaceship::updateScore(int x)
{
	this->score += x;
}

void Spaceship::updateHP(int x)
{
	this->HP += x;
}

int Spaceship::getScore()
{
	return this -> score;
}

int Spaceship::getHP()
{
	return this -> HP;
}

float Spaceship::getSpeed()
{
	return this->speed;
}

void Spaceship::setSpeed(float v)
{
	this->speed = v;
}

void Spaceship::setShootingSpeed(int value)
{
	this->shootingSpeed = value;
}


bool Spaceship::canShoot()
{
	return this->reloadingCooldown == 0;
}
