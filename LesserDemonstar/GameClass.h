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
#include "BestVector.h"

class GameClass
{

private:

	std::unique_ptr<sf::RenderWindow> window;

	sf::Texture backgroundImageTexture;
	sf::Texture bulletTexture;
	std::pair<int, int> slidingWindow;
	BestVector <Object*> activeObjects;

	Spaceship* player; // player is a singleton, as a single instace of a player must be active


	void loadTextures();
	void initWindow();
	void initVarsForBackground();
	void pollEvents();

	void update();
	void updateSlidingWindow();
	void updatePlayer();
	void updateObjects();

	void render();
	void drawBackground();
	void drawObject(Object*);
	void drawBullets();

public:

	GameClass();
	~GameClass();
	void run();
};