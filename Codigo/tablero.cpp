#include <ncurses.h>
#include "tablero.h"


Tablero::Tablero(int *mapa) 
{	
	int cont=0; //21x18

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

			else if (map[i][j] == 2) //Espacio 
			{
				mvprintw(i,2*j , " "); 
				mvprintw(i,2*j+1 , " "); 
			}

			else if (map[i][j] == 9) //Espacio en blanco
			{
				mvprintw(i,2*j , " "); 
				mvprintw(i,2*j+1 , " ");
			}

			else if (map[i][j] == 3) //Fantasmas
			{
				mvprintw(i,2*j , "="); 
				mvprintw(i,2*j+1 , "3");
			}

			else if (map[i][j] == 4) //Fantasmas
			{
				mvprintw(i,2*j , "O"); 
				mvprintw(i,2*j+1 , "<");
			}
			//mvprintw(j,i , " "); 
		}

	}

}
