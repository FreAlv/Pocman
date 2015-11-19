#include "pacman.h"

bool Pacman::rev_pared(int** map, int movX, int movY){
	if (map[x+movX][y+movY]==1){
		return false;
	}
	return true;
}

/*
Izquierda: -1, 0
Derecha: 1, 0
Arriba: 0, -1
Abajo: 0, 1
*/


void movimiento(bool pared, int movX, int movY){
	if(pared){
		x+=movX;
		y+=movY;
	}

}