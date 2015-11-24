#include <ncurses.h>
#include "pacman.h"


Pacman::Pacman(int x, int y, const char* img, int** map)
:Personaje(x , y, img)
{
	map[x][y] = 4;
}


bool Pacman::rev_pared(int movX, int movY, int** map)
{
	if (map[x+movX][y+movY]==1)
		puedeMoverse = false;
	else
		puedeMoverse = true;
}

/*
Izquierda: -1, 0
Derecha: 1, 0
Arriba: 0, -1
Abajo: 0, 1
*/

void Pacman::movimiento(int movX, int movY, int** map)
{	
	rev_pared(movX, movY, map);
	if (puedeMoverse){
		map[x][y] = 9;
		x+=movX;
		y+=movY;
		map[x][y] = 4; 
		//mvprintw(y,2*x,img);
	}
}