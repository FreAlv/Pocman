
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "fantasma.h"

Fantasma::Fantasma()
:Personaje(1, 1, "=3")
{ }

Fantasma::Fantasma(int x, int y, const char* img, int** map, int salida)
:Personaje(x , y, img)
{
	this->salida = salida;
	contador = 0;
	setPosicionActual(map[x][y]);
	map[x][y] = 3;
}

bool Fantasma::rev_pared(int movX, int movY, int** map)
{
	if (map[x+movX][y+movY]==1)
		return false;
	return true;
}

void Fantasma::dirMovimiento(int movX, int movY, int** map)
{
	map[x][y] = PosicionActual;
	x+=movX;
	y+=movY;
	PosicionActual = map[x][y];
	map[x][y] = 3;
}





void Fantasma::movimiento(int** map, Pacman pac)
{
	int num = rand()%3;
	
	if(salida > contador)
	{
		++contador;	
		return;
	}

	if (salida == contador) //new
	{
		map[x][y] = 9;
		//map[x-1][y] = 1;
		if (map[x-2][y] != 1)
			x-=2;	
		++contador;
	}

	if (num == 0)
	{
		if ((rev_pared(-1, 0, map)) and (map[x-1][y] != 3))  //Arriba: -1, 0
		{
			if (x >= pac.getX())
			{
				dirMovimiento(-1, 0, map);
				return;
			}
		}
		
		if ((rev_pared(0, -1, map)) and (map[x][y-1] != 3)) //Izquierda: 0, -1
		{
			if (y >= pac.getY())
			{
				dirMovimiento(0, -1, map);
				return;
			}
		}

		if ((rev_pared(0, 1, map)) and (map[x][y+1] != 3))  //Derecha: 0, 1
		{
			if (y <= pac.getY())
			{
				dirMovimiento(0, 1, map);
				return;
			}
		}

		if ((rev_pared(1, 0, map)) and (map[x+1][y] != 3))   //Abajo: 1, 0
		{
			if (x <= pac.getX())
			{
				dirMovimiento(1, 0, map);
				return;
			}
		}	
	}

	else if (num == 1)
	{
		if ((rev_pared(1, 0, map)) and (map[x+1][y] != 3))   //Abajo: 1, 0
		{
			if (x <= pac.getX())
			{
				dirMovimiento(1, 0, map);
				return;
			}
		}

		if ((rev_pared(0, 1, map)) and (map[x][y+1] != 3))  //Derecha: 0, 1
		{
			if (y <= pac.getY())
			{
				dirMovimiento(0, 1, map);
				return;
			}
		}		

		if ((rev_pared(-1, 0, map)) and (map[x-1][y] != 3))  //Arriba: -1, 0
		{
			if (x >= pac.getX())
			{
				dirMovimiento(-1, 0, map);
				return;
			}
		}
		
		if ((rev_pared(0, -1, map)) and (map[x][y-1] != 3)) //Izquierda: 0, -1
		{
			if (y >= pac.getY())
			{
				dirMovimiento(0, -1, map);
				return;
			}
		}	
	}	

	else if (num == 2)
	{
		if ((rev_pared(0, -1, map)) and (map[x][y-1] != 3)) //Izquierda: 0, -1
		{
			if (y >= pac.getY())
			{
				dirMovimiento(0, -1, map);
				return;
			}
		}

		if ((rev_pared(0, 1, map)) and (map[x][y+1] != 3))  //Derecha: 0, 1
		{
			if (y <= pac.getY())
			{
				dirMovimiento(0, 1, map);
				return;
			}
		}
		
		if ((rev_pared(1, 0, map)) and (map[x+1][y] != 3)) //Abajo: 1, 0
		{
			if (x <= pac.getX())
			{
				dirMovimiento(1, 0, map);
				return;
			}
		}

		if ((rev_pared(-1, 0, map)) and (map[x-1][y] != 3)) //Arriba: -1, 0
		{
			if (x >= pac.getX())
			{
				dirMovimiento(-1, 0, map);
				return;
			}
		}	
	}
}

void Fantasma::mAzul(int** map, Pacman pac)
{					 //f   c
	if ((rev_pared(0, -1, map)) and (map[x][y-1] != 3)) //Izquierda: 0, -1
	{
		if (y <= pac.getY())
		{
			dirMovimiento(0, -1, map);
			return;
		}
	}

	if ((rev_pared(0, 1, map)) and (map[x][y+1] != 3))  //Derecha: 0, 1
	{
		if (y >= pac.getY())
		{
			dirMovimiento(0, 1, map);
			return;
		}
	}
		
	if ((rev_pared(1, 0, map)) and (map[x+1][y] != 3)) //Abajo: 1, 0
	{
		if (x >= pac.getX())
		{
			dirMovimiento(1, 0, map);
			return;
		}
	}

	if ((rev_pared(-1, 0, map)) and (map[x-1][y] != 3)) //Arriba: -1, 0
	{
		if (x <= pac.getX())
		{
			dirMovimiento(-1, 0, map);
			return;
		}
	}	
}

void Fantasma::regresarCaja(int** map, Pacman pac)
{
	if ((x == pac.getX()) and (y == pac.getY()))
	{			
		posInicial(map);
		salida = 10;
	}
}

bool Fantasma::fComeP(int** map, Pacman pac)
{
	if ((x == pac.getX()) and (y == pac.getY()))
		return true;
	return false;
}

void Fantasma::posInicial(int** map)
{
		contador = 0;

		map[x][y] = 9;

		if (map[10][8] == 9) 
		{
			x = 10;
			y = 8;
			salida = 5;
		}

		else if (map[10][9] == 9)
		{
			x = 10;
			y = 9;
			salida = 10;
		}

		else if (map[10][10] == 9)
		{
			x = 10;
			y = 10;
			salida = 15;
		}

		else if (map[8][9] == 9)
		{
			x = 8;
			y = 9;
			salida = 0;
		}

		PosicionActual = 9;
		map[x][y] = 3;
}	