#pragma once
#include <algorithm>
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>
#include "Object.h"
#include "Spaceship.h"
#include "Bullet.h"
#include "Asteroid.h"
#include "BestVector.h"

class GameClass
{

private:

	std::unique_ptr<sf::RenderWindow> window;

	sf::Texture backgroundImageTexture;
	sf::Texture playerTexture;
	sf::Texture bulletTexture;
	sf::Texture asteroidTexture;
	std::pair<int, int> slidingWindow;
	BestVector <Object*> activeObjects;
	
	int spawnAsteroidEvery;
	int spawnAsteroidCooldown;
	
	Spaceship* player; // player is a singleton, as a single instace of a player must be active


	void loadTextures();
	void initWindow();
	void initVarsForBackground();
	void pollEvents();

	void update();
	void updateSlidingWindow();
	void updatePlayer();
	void updateObjects();
	void addAsteroid(); // adds asteroid if cooldown is 0

	void render();
	void drawBackground();
	void drawObject(Object*);
	void drawBullets();

public:

	GameClass();
	~GameClass();
	void run();
};