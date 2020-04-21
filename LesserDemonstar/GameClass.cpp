#include "GameClass.h"


//private functions


void GameClass::loadTextures()
{
	if (!this->backgroundImageTexture.loadFromFile("Textures/Background.png")) {
		std::cout << "Nu am reusit";
	}

	if (!this->player.texture.loadFromFile("Textures/Spaceship1.png")) {
		std::cout << "Nu am reusit";
	}
}

void GameClass::initWindow()
{
	this->window = nullptr;
	this->window = std::unique_ptr<sf::RenderWindow> (
		new sf::RenderWindow(sf::VideoMode(512, 700), 
			"LesserDemonstar", 
			sf::Style::Titlebar | sf::Style::Close)); // smart pointer for window
	this->window->setFramerateLimit(60);
}

void GameClass::initVarsForBackground()
{
	this->slidingWindow.second = 4095;
	this->slidingWindow.first = this->slidingWindow.second - 699;
}

void GameClass::pollEvents()
{
	sf::Event ev;
	while (this->window->pollEvent(ev)) {
		switch (ev.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		}
	}
}

void GameClass::update()
{
	this->pollEvents();
	this->updateSlidingWindow();
}

void GameClass::updateSlidingWindow()
{
	this->slidingWindow.first--;
	this->slidingWindow.second--;

	if (this->slidingWindow.first == -1) {
		this->slidingWindow.second = 4095;
		this->slidingWindow.first = this->slidingWindow.second - 699;
	}
}



void GameClass::render()
{

	this->window->clear();

	this->drawBackground();

	this->window->display();

}

void GameClass::drawBackground()
{
	sf::Sprite backImg;
	sf::Sprite backImgAux;
	backImg.setTexture(this->backgroundImageTexture);
	backImg.setTextureRect(sf::IntRect(0, this->slidingWindow.first, 511, this->slidingWindow.second));

	this->window->draw(backImg);
}

void GameClass::drawPlayer()
{

}

//constructor / destructor

GameClass::GameClass()
{
	this->loadTextures();
	this->initWindow();
	this->initVarsForBackground();
}


GameClass::~GameClass()
{

}


//public functions
void GameClass::run() 
{

	while (this->window->isOpen()) {

		this->update();

		this->render();
	}
}
