#include <ncurses.h>
#include "tablero.h"
#include "pacman.h"
#include "fantasma.h"


Tablero::Tablero(int *mapa) 
{	
	int cont=0; //21x18
	filas = 22;
	columnas = 19;
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

void Tablero::print(WINDOW *w)
{
	// filas = y = i, columnas = x = j
	
	/* MOVER ESTO A OTRO LUGAR, cada vez que imprime lo define otra vez y puede causarar problemas
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLUE);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	*/ 
	
	wclear(w);
	for (int i = 0; i < filas; i++)
	{ 
		for (int j = 0; j < columnas; j++)
		{
			if (map[i][j] == 0) //Bolitas
			{
				//attron(COLOR_PAIR(7));
				mvwprintw(w,i,2*j , " .");
				
				//attroff(COLOR_PAIR(7));
			}
			
			else if (map[i][j] == 1) //Paredes
			{
				//attron(COLOR_PAIR(4));
				mvwprintw(w,i,2*j , "[]");
				
				//attroff(COLOR_PAIR(4));
			} 

			else if (map[i][j] == 2) //Bolas grandes  
			{
				//attron(COLOR_PAIR(6));
				mvwprintw(w,i,2*j , "()"); 
				
				//attroff(COLOR_PAIR(6));
			}

			else if (map[i][j] == 3) //Fantasmas
			{
				//attron(COLOR_PAIR(1));
				mvwprintw(w,i,2*j , "=3"); 
				
				//attroff(COLOR_PAIR(1));
			}

			else if (map[i][j] == 4) //Pacman
			{
				//attron(COLOR_PAIR(3));
				mvwprintw(w,i,2*j, "0<");
				
				//attroff(COLOR_PAIR(3));
			}

			else if (map[i][j] == 9) //Espacio en blanco
			{
				
				mvwprintw(w,i,2*j , "  "); 
				
			}

			//mvprintw(j,i , " "); 
		}

	}
	wrefresh(w);
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