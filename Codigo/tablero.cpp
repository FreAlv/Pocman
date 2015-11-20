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

	for (int i = 0; i < f; i++)
	{ 
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] == 1)
			{
				mvprintw(j,2*i , "["); //Paredes
				mvprintw(j,2*i+1 , "]"); //Paredes
			} 
			else if (map[i][j] == 0)
			{
				mvprintw(j,2*i , " "); //Bolitas
				mvprintw(j,2*i+1 , " "); //Bolitas
			}
			else if (map[i][j] == 2)
			{
				mvprintw(j,2*i , " "); 
				mvprintw(j,2*i+1 , " "); 
			}// mvprintw(j,i , " "); //Bolotas
			else if (map[i][j] == 9) 
			{
				mvprintw(j,2*i , " "); 
				mvprintw(j,2*i+1 , " ");
			}//mvprintw(j,i , " "); //Espacio vacio
		}

	}

}
