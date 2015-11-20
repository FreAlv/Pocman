#include <ncurses.h>
#include "pacman.h"
#include "tablero.h"

void juego(Pacman pacman, Tablero tablero) // La función juego es la función principal
{
	bool pared;

	while(true)
	{	
		int tecla = getch();
		
		if(tecla == KEY_LEFT) 
		{ 	
			pared = pacman.rev_pared(tablero.getMap(),-1,0);
			if(pared) // este if es provisional
			{
				clear();
				tablero.print();
			}
			pacman.movimiento(pared, -1, 0);
		}
		else if(tecla == KEY_RIGHT) 
		{	
			pared = pacman.rev_pared(tablero.getMap(),1,0);
			if(pared) // este if es provisional
			{
				clear();
				tablero.print();
			}
			pacman.movimiento(pared,1,0);
		}
		else if(tecla == KEY_UP)
		{
			pared = pacman.rev_pared(tablero.getMap(),0, -1);
			if(pared) // este if es provisional
			{
				clear();
				tablero.print();
			}
			pacman.movimiento(pared, 0, -1);
		}
		else if(tecla == KEY_DOWN)
		{
			pared = pacman.rev_pared(tablero.getMap(),0, 1);
			if(pared) // este if es provisional
			{
				clear();
				tablero.print();
			}
			pacman.movimiento(pared, 0, 1);
		}
		else if(tecla == 'q') break;
	}
}

int main() 
{
	int mapa[]={ //22 x 19 //Pacman: 16,09 (x,y)
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 2, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 2, 1,
		1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1,
		1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1,
		1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1,
		1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1,
		1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1,
		1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1,
		1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
		1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 1,
		1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1,
		1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	
	// el array del mapa puede ir en un archivo extra,
	Tablero tablero(mapa);
	Pacman pacman(9,15, ">O");
	
	initscr();// Todo esto es del ncurses, luego irá en una clase propia
	clear();
	noecho();						
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
	
	juego(pacman, tablero); 
	
	endwin();
	return 0;

}
