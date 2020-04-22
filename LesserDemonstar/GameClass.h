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


class GameClass 
{

private:
	
	std::unique_ptr<sf::RenderWindow> window;

	sf::Texture backgroundImageTexture;
	std::pair<int, int> slidingWindow;

	Spaceship* player; // player is a singleton, as a single instace of a player must be active
	

	void loadTextures();
	void initWindow();
	void initVarsForBackground();
	void pollEvents();

	void update();
	void updateSlidingWindow();  
	void updatePlayer();

	void render();
	void drawBackground();
	void drawPlayer();

public:

	GameClass();
	~GameClass();
	void run();
};

