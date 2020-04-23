#include "Object.h"

float Object::getSpeed()
{
	return speed;
}

bool Object::collidesWith(Object* other)
{
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
}

Object::~Object()
{
	std::cout << "Obiect distrus\n";
}

Object* Object::Create(ObjectType type)
{
	if (type == OT_Bullet) {
		
	}
	return nullptr;
}
