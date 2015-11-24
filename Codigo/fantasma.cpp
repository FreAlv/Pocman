#include <ncurses.h>
#include "fantasma.h"

Fantasma::Fantasma(int x, int y, const char* img, int** map)
:Personaje(x , y, img)
{
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
	/*if ((cordenada_C_POC <= cordenada_C_FAN) 
	{	
		if (m[cordenada_F_FAN][cordenada_C_FAN-1] != 1))
		{
			m[cordenada_F_FAN][cordenada_C_FAN] = 0;
			cordenada_C_FAN -= 1;
			m[cordenada_F_FAN][cordenada_C_FAN] = 3;
			cout << "CACA 1" << endl;
			return;
	}*/
	// filas = y = i, columnas = x = j

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
			map[x][y] = 0;
			x-=1;
			y+=0;	
			map[x][y] = 3;
			return;
		}
	}
		
	if (rev_pared(0, -1, map))
	{
		if (y >= pac.getY())
		{
			map[x][y] = 0;
			x+=0;
			y-=1;	
			map[x][y] = 3;
			return;
		}
	}

	if (rev_pared(0, 1, map))
	{
		if (y <= pac.getY())
		{
			map[x][y] = 0;
			x+=0;
			y+=1;	
			map[x][y] = 3;
			return;
		}
	}

	if (rev_pared(1, 0, map))
	{
		if (x <= pac.getX())
		{
			map[x][y] = 0;
			x+=1;
			y+=0;	
			map[x][y] = 3;
			return;
		}
	}	
}


//Prueba en poner esto para que los fantasmas no vuelvan a poner bolitas, pon esto en vez de : map[x][y] = 0;
/*
if(map[x][y] == 0)// bolitas
{
	map[x][y] = 0;
}
else if(map[x][y] == 2;) //bolas
{
	map[x][y] = 2;
}
else if(map[x][y] == 9;) //espacio en blanco
{
	map[x][y] = 9;
}
*/