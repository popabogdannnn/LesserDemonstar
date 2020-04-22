#include "GameClass.h"


//private functions


void GameClass::loadTextures()
{
	if (!this->backgroundImageTexture.loadFromFile("Textures/Background.png")) {
		std::cout << "Nu am reusit";
	}

	if (!this->player->texture.loadFromFile("Textures/Spaceship.png")) {
		std::cout << "Nu am reusit";
	}

	this->player->xSize = 128;
	this->player->ySize = 128;

	this->player->pos.x = this->window->getSize().x / 2 - this->player->xSize / 2;
	this->player->pos.y = this->window->getSize().y - this->player->ySize;
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
	this->updatePlayer();
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

void GameClass::updatePlayer()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (this->player->pos.x > 0) {
			this->player->pos.x -= this->player->getSpeed();
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (this->player->pos.x + this->player->xSize < 512) {
			this->player->pos.x += this->player->getSpeed();
		}
	}
}



void GameClass::render()
{

	this->window->clear();

	this->drawBackground();
	this->drawPlayer();

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
	sf::Sprite playerSpaceship;
	playerSpaceship.setTexture(this->player->texture);
	playerSpaceship.setPosition(this->player->pos);
	
	this->window->draw(playerSpaceship);
}

//constructor / destructor

GameClass::GameClass()
{
	this->initWindow();
	this->player = player->getInstance();
	this->loadTextures();
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
