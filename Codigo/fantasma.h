
#ifndef FANTASMA_H
#define FANTASMA_H

#include "personaje.h"
#include "pacman.h"

class Fantasma: public Personaje
{
	int PosicionActual;
	int salida;
	int contador = 0;
public:
	Fantasma();
	Fantasma(int x, int y, const char* img, int** map, int num);
	bool rev_pared(int movX, int movY, int** map);
	void movimiento( int** map, Pacman pac);
	int getPosicionActual() { return PosicionActual; }
	void setPosicionActual(int Valor) { PosicionActual = Valor; }
	int getSalida() { return salida; }
	int getContador() { return contador; }
	void setContador() { contador+=1; }
};

#endif // FANTASMA_H
