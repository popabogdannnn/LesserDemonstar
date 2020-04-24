#pragma once
#include <exception>
#include <cstring>
#include <iostream>

class myException :
	public std::exception
{
private:
	char* str;
public:
	myException(const char* = "");
	~myException();
	virtual const char* what() const throw();

};

