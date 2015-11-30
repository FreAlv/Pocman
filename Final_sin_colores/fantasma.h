
#ifndef FANTASMA_H
#define FANTASMA_H

#include "personaje.h"
#include "pacman.h"
#include "controljuego.h"

class Fantasma: public Personaje
{
	int PosicionActual;
	int salida;
	int contador;
	void dirMovimiento(int movX, int movY, int** map);
	bool rev_pared(int movX, int movY, int** map);
public:
	Fantasma();
	Fantasma(int x, int y, const char* img, int** map, int salida);
	
	void movimiento( int** map, Pacman pac);
	void mAzul(int** map, Pacman pac);
	
	void regresarCaja(int** map, Pacman pac);
	bool fComeP(int** map, Pacman pac);
	
	void posInicial(int** map);
};

#endif // FANTASMA_H
