#include <ncurses.h>
#include "tablero.h"
#include "pacman.h"
#include "fantasma.h"


Tablero::Tablero(int *mapa) 
{	
	int cont=0; //21x18
	filas = 22;
	columnas = 19;
	
	copyMap = new int* [22];
	map = new int* [22];
	for (int i = 0; i < 22; i++)
	{
		map[i] = new int[19];
		copyMap[i] = new int[19];
	}
	
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			map[i][j] = mapa[cont];
			copyMap[i][j] = mapa[cont];
			cont++;
		}
	}
	
}

void Tablero::print(WINDOW *w)
{
	wclear(w);
	for (int i = 0; i < filas; i++)
	{ 
		for (int j = 0; j < columnas; j++)
		{
			if (map[i][j] == 0) //Bolitas
				mvwprintw(w,i,2*j , " .");
			
			else if (map[i][j] == 1) //Paredes
				mvwprintw(w,i,2*j , "[]");

			else if (map[i][j] == 2) //Bolas grandes  
				mvwprintw(w,i,2*j , "()"); 

			else if (map[i][j] == 3) //Fantasmas
				mvwprintw(w,i,2*j , "=3");

			else if (map[i][j] == 4) //Pacman
				mvwprintw(w,i,2*j, "0<");

			else if (map[i][j] == 9) //Espacio en blanco
				mvwprintw(w,i,2*j , "  "); 
		}

	}
	wrefresh(w);
}

void Tablero::restablecerMapa()
{
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			map[i][j] = copyMap[i][j];
		}
	}
}


bool Tablero::ganar()
{
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if ((map[i][j] == 0) or (map[i][j] == 2))
				return false;
		}
	}
	return true;
}