#ifndef FANTASMA_H
#define FANTASMA_H

#include "personaje.h"
class Fantasma: public Personaje
{
public:
	bool rev_pared(int** map, int movX, int movY);
	void movimiento(bool pared, int movX, int movY) ;
	
};

#endif // FANTASMA_H
