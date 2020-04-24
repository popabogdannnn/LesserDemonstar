#include "GameClass.h"


//private functions


std::string GameClass::intToString(int X)
{
	std::string ret;
	
	do {
		ret.push_back('0' + X % 10);
		X /= 10;
	} while (X);

	std::reverse(ret.begin(), ret.end());

	return ret;
}

void GameClass::loadTextures()
{
	try {
		if (!this->backgroundImageTexture.loadFromFile("Textures/Background.png")) {
			throw myException("Textures/Background.png");
		}

		if (!this->playerTexture.loadFromFile("Textures/Spaceship.png")) {
			throw myException("Textures/Spaceship.png");
		}

		if (!this->bulletTexture.loadFromFile("Textures/Laser.png")) {
			throw myException("Textures/Laser.png");
		}

		if (!this->asteroidTexture.loadFromFile("Textures/Meteorite.png")) {
			throw myException("Textures/Meteorite.png");
		}

		if (!this->textFont.loadFromFile("Textures/font.ttf")) {
			throw myException("Textures/font.ttf");
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << "\n";
		system("pause");
		exit(0);
	}
}

void GameClass::initWindow()
{
	this->window = nullptr;
	this->window = std::unique_ptr<sf::RenderWindow>(
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
	this->addAsteroid();
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
			this->player->shoot();
			Object* obj = Object::Create(OT_Bullet, 0, 0, -15, bulletTexture);
			obj->pos.x = this->player->pos.x + this->player->xSize / 2 - obj->xSize / 2;
			obj->pos.y = this->player->pos.y - obj->ySize - 3 * obj->getSpeed();
			this->activeObjects += obj;
		}
	}

	for (int i = 0; i < activeObjects(); i++) {
		if (Asteroid* asteroid = dynamic_cast<Asteroid*>(activeObjects[i]); asteroid != nullptr) {
			if (asteroid->pos.y >= this->window->getSize().y - this->player->ySize - asteroid->ySize) {
				if (this->player->collidesWith(asteroid)) {
					asteroid->pos.x = -100;
					this->player->updateHP(-asteroid->getDamage());
				}
			}
		}
	}

	if (this->player->getHP() == 0) {
		
	}
}

void GameClass::updateObjects()
{
	Object* del = nullptr;
	
	//update positions
	for (int i = 0; i < this->activeObjects(); i++) {
		this->activeObjects[i]->pos.y += this->activeObjects[i]->getSpeed();
	}

	//check collisions, if collides then move out of screen

	bool ok = false;
	for (int i = 0; i < this->activeObjects() && !ok; i++) {
		if (Bullet* bullet = dynamic_cast<Bullet*>(activeObjects[i]); bullet != nullptr) {
			for (int j = 0; j < this->activeObjects() && !ok; j++) {
				if (Asteroid* asteroid = dynamic_cast<Asteroid*>(activeObjects[j]); asteroid != nullptr) {
					if (bullet->collidesWith(asteroid)) {
						asteroid->updateHP(-bullet->getDamage());
						ok = true;
						bullet->pos.x = -100;
						if (asteroid->getHP() <= 0) {
							this->player->updateScore(10);
							asteroid->pos.x = -200;
						}
					}
				}
			}
		}
	}


	//delete out of screen objects
	for (int i = 0; i < this->activeObjects(); i++) {
		if (auto position = this->activeObjects[i]->pos.y; position < -65 || position > 700) {
			del = this->activeObjects[i];
			this->activeObjects -= del;
			delete del;
			i--;
		}
	}
}


void GameClass::addAsteroid()
{
	if (this->spawnAsteroidCooldown == 0) {
		
		this->activeObjects += Object::Create(
			OT_Asteroid,
			rand() % int(512 - this->asteroidTexture.getSize().x),
			-int(this->asteroidTexture.getSize().y),
			3,
			this->asteroidTexture
		 );
		//std::cout << -int(this->asteroidTexture.getSize().y) << "\n";
		this->spawnAsteroidCooldown = this->spawnAsteroidEvery + rand() % 100;
	}
	this->spawnAsteroidCooldown--;
}



void GameClass::render()
{

	this->window->clear();
	this->drawBackground();
	this->drawObject(this->player);
	this->drawBullets();
	this->drawPlayerStats();
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

void GameClass::drawObject(Object* obj)
{
	sf::Sprite objSprite;
	objSprite.setTexture(obj->texture);
	objSprite.setPosition(obj->pos);

	this->window->draw(objSprite);
}

void GameClass::drawBullets()
{
	for (int i = 0; i < this->activeObjects(); i++) {
		this->drawObject(this->activeObjects[i]);
	}
}

void GameClass::drawPlayerStats()
{
	sf::Text scoreText;
	scoreText.setFont(this->textFont);
	scoreText.setCharacterSize(24);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(sf::Vector2f(5, 5));
	scoreText.setString("Score: " + this->intToString(this->player->getScore()));
	
	this->window->draw(scoreText);

	sf::Text healthText;
	healthText.setFont(this->textFont);
	healthText.setCharacterSize(24);
	healthText.setFillColor(sf::Color::White);
	healthText.setPosition(sf::Vector2f(5, 34));
	healthText.setString("HP: " + this->intToString(this->player->getHP()));

	this->window->draw(healthText);
}



//constructor / destructor

GameClass::GameClass()
{
	this->spawnAsteroidEvery = 1 * 60;
	this->spawnAsteroidCooldown = 0;
	this->loadTextures();
	this->initWindow();
	this->player = player->getInstance(0, 0, 5.0, this->playerTexture);
	this->player->pos.x = this->window->getSize().x / 2 - this->player->xSize / 2;
	this->player->pos.y = this->window->getSize().y - this->player->ySize;
	this->initVarsForBackground();
	this->gameState = 0;
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