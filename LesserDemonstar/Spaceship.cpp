#include "Spaceship.h"

//private functions

Spaceship::Spaceship()
{
	//std::cout << "IM ALIVE\n";
	this->score = 0;
	this->speed = 2.5;
	this->HP = 100;
	this->shootingSpeed = 25;
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

Bullet* Spaceship::shoot(sf::Texture bulletTexture)
{

	this->reloadingCooldown = this->shootingSpeed;
	Bullet* newBullet = new Bullet(bulletTexture);
	newBullet->pos.x = this->pos.x + this->xSize / 2 - newBullet->xSize / 2;
	newBullet->pos.y = this->pos.y - newBullet->ySize - 3 * newBullet->getSpeed();
	return newBullet;
}


bool Spaceship::canShoot()
{
	return this->reloadingCooldown == 0;
}