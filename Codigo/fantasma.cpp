#include <ncurses.h>
#include "fantasma.h"

Fantasma::Fantasma(int x, int y, const char* img, int** map)
:Personaje(x , y, img)
{
	setPosicionActual(map[x][y]);
	map[x][y] = 3;
}

bool Fantasma::rev_pared(int movX, int movY, int** map)
{
	if (map[x+movX][y+movY]==1)
		return false;
	return true;
}

void Fantasma::movimiento(int** map, Pacman pac)
{
		/*
		Izquierda: 0, -1
		Derecha: 0, 1
		Arriba: -1, 0
		Abajo: 1, 0
		*/
	if (rev_pared(-1, 0, map))
	{
		if (x >= pac.getX())
		{
			map[x][y] = PosicionActual;
			x-=1;
			y+=0;
			PosicionActual = map[x][y];
			map[x][y] = 3;
			return;
		}
	}
		
	if (rev_pared(0, -1, map))
	{
		if (y >= pac.getY())
		{
			map[x][y] = PosicionActual;
			x+=0;
			y-=1;
			PosicionActual = map[x][y];
			map[x][y] = 3;
			return;
		}
	}

	if (rev_pared(0, 1, map))
	{
		if (y <= pac.getY())
		{
			map[x][y] = PosicionActual;
			x+=0;
			y+=1;	
			PosicionActual = map[x][y];
			map[x][y] = 3;
			return;
		}
	}

	if (rev_pared(1, 0, map))
	{
		if (x <= pac.getX())
		{
			map[x][y] = PosicionActual;
			x+=1;
			y+=0;	
			PosicionActual = map[x][y];
			map[x][y] = 3;
			return;
		}
	}	
}
