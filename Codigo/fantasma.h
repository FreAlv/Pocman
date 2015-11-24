
#ifndef FANTASMA_H
#define FANTASMA_H

#include "personaje.h"
#include "pacman.h"

class Fantasma: public Personaje
{
	int PosicionActual;
public:
	Fantasma(int x, int y, const char* img, int** map);
	bool rev_pared(int movX, int movY, int** map);
	void movimiento( int** map, Pacman pac);
	int getPosicionActual() { return PosicionActual; }
	void setPosicionActual(int Valor) { PosicionActual = Valor; }
};

#endif // FANTASMA_H
