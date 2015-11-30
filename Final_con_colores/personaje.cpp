#include "personaje.h"

Personaje::Personaje(int x, int y, const char* img)
{
	this->x = x;
	this->y =y;
	copyX = x;
	copyY = y;
	this->img =img;
	
}
