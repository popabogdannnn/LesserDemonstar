#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>

/*
	class Object defines an entity on the screen (player's spaceship, asteroid, etc.)
	(x. y) left side up coordinate
	(xSize, ySize) pixels on x axis and y axis
*/

class Object
{
protected:
	float speed;

public:
	float getSpeed();
	sf::Vector2f pos;
	int xSize, ySize;
	sf::Texture texture;
	std::vector< std::vector <bool> > hasPixelSet;
	bool collidesWith(Object*); // two objects collide if at least two set pixels overlap
};
