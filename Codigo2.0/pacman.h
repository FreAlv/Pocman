#ifndef PACMAN_H
#define PACMAN_H

#include "personaje.h"

class Pacman: public Personaje
{
	int PosicionActual;
	bool puedeMoverse;
public:
	Pacman(int x, int y, const char* img, int** map);
	bool rev_pared(int movX, int movY, int** map);
	void movimiento(int movX, int movY, int** map);
	int getPocisionActual() { return PosicionActual; }
};

#endif // PACMAN_H
