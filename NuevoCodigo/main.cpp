
#include <ncurses.h>
//#include <thread>
#include <iostream>
#include <vector>

#include "pacman.h"
#include "tablero.h"
#include "fantasma.h"

#define TIEMPO 10

using namespace std;

//vector<thread*> Ts;
void esperar(int* _tecla)
{
	system ("/bin/stty -icanon");
	int tecla = getch();
	*_tecla=tecla;
}

void juego(Pacman pacman, Fantasma* F, Tablero tablero) // La función juego es la función principal
{
	bool pared;
	
	int tecla;
	int *ptr_tecla=&tecla;
	while(/*(pacman.getX() != F1.getX()) or (pacman.getY() != F1.getY())*/true)//cuando este en azul hay que cambiar
	{	
		int tecla = getch();
		//Ts.push_back(new thread(esperar, ptr_tecla));	

		if(tecla == KEY_UP)
		{ 	
			pacman.movimiento(-1, 0, tablero.getMap());
			tablero.print();
		}
		
		if(tecla == KEY_DOWN) 
		{	
			pacman.movimiento(1,0, tablero.getMap());
			tablero.print();
		}

		if(tecla == KEY_LEFT)
		{

			pacman.movimiento(0, -1, tablero.getMap());
			tablero.print();				
		}

		if(tecla == KEY_RIGHT)
		{
			pacman.movimiento(0, 1, tablero.getMap());
			tablero.print();	
		}

		//F1.movimiento(tablero.getMap(), pacman);
		if(tecla == 'q') break;
		//Ts.clear();
		if (tablero.ganar())
		{
			break;
		}

		//para la salida de los fantasmas
		for (int i = 0; i < 3; i++)
		{
		 	F[i].setContador();
		 	if (F[i].getContador() > F[i].getSalida())
				F[i].movimiento(tablero.getMap(), pacman);
		} 
	}
}

int main() 
{

	int mapa[]={ //22 x 19 //Pacman: 16,09 (x,y)
      //0  1  2  3  4  5  6  7  8  9 10         		
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, //0
		1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, //1
		1, 2, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 2, 1,
		1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, //5
		1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1,
		1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1,
		1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1,
		1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, //10
		1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1,
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
	Pacman pacman(16,9, "0<", tablero.getMap());
	Fantasma* fantasmas;
	fantasmas = new Fantasma[3];
	*(fantasmas + 0) = Fantasma(10, 8, "=3", tablero.getMap(), 5);
	*(fantasmas + 1) = Fantasma(10, 9, "=3", tablero.getMap(), 20);
	*(fantasmas + 2) = Fantasma(10, 10, "=3", tablero.getMap(), 40);
	
	initscr();// Todo esto es del ncurses, luego irá en una clase propia
	clear();
	noecho();						
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);


	juego(pacman, fantasmas, tablero); 
	
	endwin();
	return 0;

}
