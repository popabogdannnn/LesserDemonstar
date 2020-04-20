#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>

class GameClass {

private:
	
	std::unique_ptr <sf::RenderWindow> window;
	
	void initWindow();

public:

	GameClass();
	~GameClass();
	void run();
};

