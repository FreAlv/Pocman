#ifndef PACMAN_H
#define PACMAN_H

#include "personaje.h"
#include "controljuego.h"

class Pacman: public Personaje
{
	bool puedeMoverse;
	
public:
	Pacman(int x, int y, const char* img, int** map);
	bool rev_pared(int movX, int movY, int** map);
	void movimiento(int movX, int movY, int** map, ControlJuego *control );
	void posInicial(int** map);  //SE PUDE PONER VIRTUAL PURA
};

#endif // PACMAN_H
