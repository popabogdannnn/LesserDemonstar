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
#include "myException.h"

class GameClass
{

private:

	std::unique_ptr<sf::RenderWindow> window;

	sf::Font textFont;
	sf::Texture backgroundImageTexture;
	sf::Texture playerTexture;
	sf::Texture bulletTexture;
	sf::Texture asteroidTexture;
	sf::Texture playButtonTexture0;
	sf::Texture playButtonTexture1;
	sf::Texture logoTexture;
	sf::Texture gameOverTexture;
	std::pair<int, int> slidingWindow;
	BestVector <Object*> activeObjects;
	
	int spawnAsteroidEvery;
	int spawnAsteroidCooldown;
	int gameState; // gameState = 0 in menu, = 1 in game, = 2 in game over
	
	Spaceship* player; // player is a singleton, as a single instace of a player must be active

	std::string intToString(int);

	void loadTextures();
	void initWindow();
	void initVarsForBackground();
	void pollEvents();

	void update();
	void updateMenu();
	void updateInGame();
	void updateGameOver();
	void pollEventPlayButton();

	void updateSlidingWindow();
	void updatePlayer();
	void updateObjects();
	void addAsteroid(); // adds asteroid if cooldown is 0

	void render();
	void renderMenu();
	void renderInGame();
	void renderGameOver();

	void drawBackground();
	void drawLogo();
	void drawText(int, int, int, std::string);
	void drawPlayButton();
	void drawGameOver();
	void drawObject(Object*);
	void drawBullets();
	void drawPlayerStats();
	void drawCredentials();


public:

	GameClass();
	~GameClass();
	void run();
};