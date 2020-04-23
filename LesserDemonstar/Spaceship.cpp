#include "Spaceship.h"

//private functions

Spaceship::Spaceship(float _x, float _y, float _speed, sf::Texture _texture): Object(_x, _y, _speed, _texture)
{
	//std::cout << "IM ALIVE\n";
	this->score = 0;
	this->HP = 100;
	this->shootingSpeed = 13;
}

//public functions

Spaceship::~Spaceship()
{
	delete this->instance;
	this->instance = nullptr;
}

Spaceship* Spaceship::getInstance(float _x, float _y, float _speed, sf::Texture _texture)
{
	if (this->instance == nullptr) {
		this->instance = new Spaceship(_x, _y, _speed, _texture);
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
	return this->score;
}

int Spaceship::getHP()
{
	return this->HP;
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

void Spaceship::updateReloadingCooldown()
{
	auto max = [](auto a, auto b) {return a > b ? a : b; };
	this->reloadingCooldown = max(this->reloadingCooldown - 1, 0);
}

void Spaceship::shoot()
{

	this->reloadingCooldown = this->shootingSpeed;
}


bool Spaceship::canShoot()
{
	return this->reloadingCooldown == 0;
}