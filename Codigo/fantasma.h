#ifndef FANTASMA_H
#define FANTASMA_H

#include "personaje.h"
#include "pacman.h"

class Fantasma: public Personaje
{
public:
	Fantasma(int x, int y, const char* img, int** map);
	bool rev_pared(int** map, int movX, int movY);
	void movimiento( int** map, Pacman pac);
	
};

#endif // FANTASMA_H
