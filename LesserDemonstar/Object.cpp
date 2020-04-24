#include "Object.h"

float Object::getSpeed()
{
	return speed;
}

bool Object::collidesWith(Object* other)
{
	auto max = [](auto a, auto b) {return a > b ? a : b; };
	auto min = [](auto a, auto b) {return a < b ? a : b; };
	if (max(this->pos.x, other->pos.x) > min(this->pos.x + this->xSize, other->pos.x + other->xSize)) {
		return false;
	}
		
	for (int x = 0; x < this->xSize; x++) {
		for (int y = 0; y < this->ySize; y++) {
			if (this->hasPixelSet[x][y]) {
				int onScreenX = this->pos.x + x;
				int onScreenY = this->pos.y + y; // onscreen coordinate of pixel
				
				int otherX = onScreenX - other->pos.x;
				int otherY = onScreenY - other->pos.y; // coordinate of pixel relative to other object
				//std::cout << onScreenX << " " << onScreenY << "\n";
				//getchar();
				if (otherX >= 0 && otherX < other->xSize && otherY >= 0 && otherY < other->ySize) {
					if (other->hasPixelSet[otherX][otherY]) {
						return true;
					}
				}
			}
		}
	}

	return false;
}

Object::Object()
{

}

Object::Object(float _x, float _y, float _speed, sf::Texture _texture)
{
	this->pos.x = _x;
	this->pos.y = _y;
	this->speed = _speed;
	this->texture = _texture;
	this->xSize = _texture.getSize().x;
	this->ySize = _texture.getSize().y;
	this->hasPixelSet.resize(this->xSize);
	for (int i = 0; i < xSize; i++) {
		this->hasPixelSet[i].resize(this->ySize);
	}

	sf::Image img = _texture.copyToImage();

	for (int x = 0; x < xSize; x++) {
		for (int y = 0; y < ySize; y++) {
			sf::Color col = img.getPixel(x, y);
			if (col.a != 0) {
				hasPixelSet[x][y] = true;
			}
		}
	}
}

Object::~Object()
{
	//std::cout << "Obiect distrus\n";
}


