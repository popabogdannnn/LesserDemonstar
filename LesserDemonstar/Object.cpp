#include "Object.h"

float Object::getSpeed()
{
	return speed;
}

bool Object::collidesWith(Object* other)
{
	return false;
}
