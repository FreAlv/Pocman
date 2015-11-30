#include <ncurses.h>
#include "tablero.h"



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

void Tablero::print(ControlJuego control)
{
	wclear(control.getPantJuego());
	for (int i = 0; i < filas; i++)
	{ 
		for (int j = 0; j < columnas; j++)
		{
			if (map[i][j] == 0) //Bolitas
			{
				wattron(control.getPantJuego(), COLOR_PAIR(7));
				mvwprintw(control.getPantJuego(),i,2*j , " .");
				wattroff(control.getPantJuego(), COLOR_PAIR(7));

			}
			
			else if (map[i][j] == 1) //Paredes
			{
				wattron(control.getPantJuego(), COLOR_PAIR(4));
				mvwprintw(control.getPantJuego(),i,2*j , "[]");
				wattroff(control.getPantJuego(), COLOR_PAIR(4));
			} 

			else if (map[i][j] == 2) //Bolas grandes  
			{
				wattron(control.getPantJuego(), COLOR_PAIR(6));
				mvwprintw(control.getPantJuego(),i,2*j , "()"); 
				wattroff(control.getPantJuego(), COLOR_PAIR(6));

			}

			else if (map[i][j] == 3) //Fantasmas
			{
				int color;
				if(control.getmodoAzul())
					color = 5;
				else
					color = 1;
				wattron(control.getPantJuego(), COLOR_PAIR(color));
				mvwprintw(control.getPantJuego(),i,2*j , "=3");
				wattroff(control.getPantJuego(), COLOR_PAIR(color));
			}

			else if (map[i][j] == 4) //Pacman
			{
				wattron(control.getPantJuego(), COLOR_PAIR(3));
				mvwprintw(control.getPantJuego(),i,2*j, "0<");
				wattroff(control.getPantJuego(), COLOR_PAIR(3));
			}

			else if (map[i][j] == 9) //Espacio en blanco
			{
				mvwprintw(control.getPantJuego(),i,2*j , "  "); 
			}
		}

	}
	wrefresh(control.getPantJuego());
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