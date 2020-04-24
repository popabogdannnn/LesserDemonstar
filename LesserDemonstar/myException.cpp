#include "myException.h"

myException::myException(const char* msg)
{
	str = new char[strlen("Couldn't find image in ") + strlen(msg) + 3];
	memset(str, 0, strlen("Couldn't find image in ") + strlen(msg));
	memcpy(str, "Couldn't find image in ", strlen("Couldn't find image in "));
	memcpy(str + strlen("Couldn't find image in "), msg, strlen(msg));
	str[strlen("Couldn't find image in ") + strlen(msg)] = 0;
}

myException::~myException()
{
	delete[]str;
}

const char* myException::what() const throw()
{
	return str;
}
