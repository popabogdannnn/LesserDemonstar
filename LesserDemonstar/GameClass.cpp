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

	if (!this->bulletTexture.loadFromFile("Textures/Laser.png")) {
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
	this->updateObjects();
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

	this->player->updateReloadingCooldown();

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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		if (this->player->canShoot()) {
			activeBullets += this->player->shoot(this->bulletTexture);
		}
	}
}

void GameClass::updateObjects()
{
	Bullet* del = nullptr;
	//std::cout << this->activeBullets() << "\n";
	
	for (int i = 0; i < this->activeBullets(); i++) {
		this->activeBullets[i]->pos.y += this->activeBullets[i]->getSpeed();
		//std::cout << this->activeBullets[i]->pos.y << "\n";
		if (auto position = this->activeBullets[i]->pos.y; position < -20) {
			del = this->activeBullets[i];
		}
	}

	if (del != nullptr) {
		this->activeBullets -= del;
	}
}



void GameClass::render()
{

	this->window->clear();

	this->drawBackground();
	this->drawObject(this -> player);
	this->drawBullets();
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

void GameClass::drawObject(Object *obj)
{       
	sf::Sprite objSprite;
	objSprite.setTexture(obj->texture);
	objSprite.setPosition(obj->pos);
	
	this->window->draw(objSprite);
}

void GameClass::drawBullets()
{
	for (int i = 0; i < this->activeBullets(); i++) {
		this->drawObject(this->activeBullets[i]);
	}
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
