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

		
		map[x][y] = 9;
		x+=movX;
		y+=movY;
		
		if (map[x][y] == 0) //Come bolita
		{
			control->aumentarPuntuacion(100);
			control->printDatos();
		}
		
		if (map[x][y] == 2) //Come bola
		{
			control->setmodoAzul(true);
			control->aumentarPuntuacion(200);
			control->printDatos();
		}
		
		if(y < 0)
		{
			y=18;
			control->aumentarPuntuacion(-100);// para que no aumente la puntuacion
			control->printDatos();
		}
		if(y > 18) 
		{
			y = 0;
			control->aumentarPuntuacion(-100);
			control->printDatos();
		}
		
		map[x][y] = 4; 
	}

}

void Pacman::posInicial(int** map)
{
	map[x][y] = 9;
	x = copyX;
	y = copyY;
	map[x][y] = 4;
}