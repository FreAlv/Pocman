#include <ncurses.h>
#include "tablero.h"
#include "pacman.h"
#include "fantasma.h"

Tablero::Tablero(int *mapa) 
{	
	int cont=0; //21x18
	Filas = 22;
	Columnas = 19;
	map = new int* [22];
	for (int i = 0; i < 22; i++)
		map[i] = new int[19];

	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			map[i][j] = mapa[cont];
			cont++;
		}
	}
}

void Tablero::print()
{
	int f = 22;
	int c = 19;
	// filas = y = i, columnas = x = j
	
	clear();
	for (int i = 0; i < f; i++)
	{ 
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] == 0) //Bolitas
			{
				mvprintw(i,2*j , " "); 
				mvprintw(i,2*j+1 , "."); 
			}
			
			else if (map[i][j] == 1) //Paredes
			{
				mvprintw(i,2*j , "[");
				mvprintw(i,2*j+1 , "]"); 
			} 

			else if (map[i][j] == 2) //Bolas grandes  
			{
				mvprintw(i,2*j , "("); 
				mvprintw(i,2*j+1 , ")");
			}

			else if (map[i][j] == 3) //Fantasmas
			{
				mvprintw(i,2*j , "="); 
				mvprintw(i,2*j+1 , "3");
			}

			else if (map[i][j] == 4) //Pacman
			{
				mvprintw(i,2*j, "0");
				mvprintw(i,2*j+1, "<");
			}

			else if (map[i][j] == 9) //Espacio en blanco
			{
				mvprintw(i,2*j , " "); 
				mvprintw(i,2*j+1 , " ");
			}

			//mvprintw(j,i , " "); 
		}

	}
	refresh();
}

bool Tablero::ganar()
{
	for (int i = 0; i < Filas; i++)
	{
		for (int j = 0; j < Columnas; j++)
		{
			if ((map[i][j] == 0) or (map[i][j] == 2))
				return false;
		}
	}
	return true;
}