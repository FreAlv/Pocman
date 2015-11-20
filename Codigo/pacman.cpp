#include<ncurses.h>
#include "pacman.h"

Pacman::Pacman(int x, int y, const char* img): Personaje(x , y, img){}


bool Pacman::rev_pared(int** map, int movX, int movY)
{
	if (map[x+movX][y+movY]==1)
		return false;
	return true;
}

/*
Izquierda: -1, 0
Derecha: 1, 0
Arriba: 0, -1
Abajo: 0, 1
*/


void Pacman::movimiento(bool pared, int movX, int movY)
{
	if(pared)
	{	
		x+=movX;
		y+=movY;
		mvprintw(y,2*x,img);
		refresh();

	}

}