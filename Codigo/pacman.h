#ifndef PACMAN_H
#define PACMAN_H

#include "personaje.h"

class Pacman: public Personaje
{
public:
	Pacman(int x,int y, const char* img);
	bool rev_pared(int** map, int movX, int movY);
	void movimiento(bool pared, int movX, int movY);
};

#endif // PACMAN_H
