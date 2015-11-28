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

void Pacman::movimiento(int movX, int movY, int** map, ControlJuego *control)
{	

	rev_pared(movX, movY, map);
	if (puedeMoverse)
	{
		if (map[x+movX][y+movY] == 0) //Come bolita
		{
			control->aumentarPuntuacion(100);
			control->printDatos();
		}
		
		if (map[x+movX][y+movY] == 2) //Come bola
		{
			control->setmodoAzul(true);
			control->aumentarPuntuacion(200);
			control->printDatos();
		}
		
		map[x][y] = 9;
		x+=movX;
		y+=movY;
		map[x][y] = 4; 
		//mvprintw(y,2*x,img);
	}

}

void Pacman::posInicial(int** map)
{
	map[x][y] = 9;
	x = 16;
	y = 9;
	map[x][y] = 4;
}