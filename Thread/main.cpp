
#include <ncurses.h>
#include <thread>
#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>

#include "pacman.h"
#include "tablero.h"
#include "fantasma.h"

//#define TIEMPO 700

using namespace std;

void esperar(Pacman *pacman, Tablero *tablero)
{
	system ("/bin/stty -icanon");
	int tecla = getch();
	bool pared;
	while(tecla!='q')
	{
		
	if(tecla == KEY_UP)
	{ 	
		pacman->movimiento(-1, 0, tablero->getMap());
		//tablero->print();
	}
		
	if(tecla == KEY_DOWN) 
	{	
		pacman->movimiento(1,0, tablero->getMap());
		//tablero->print();
	}

	if(tecla == KEY_LEFT)
	{
		pacman->movimiento(0, -1, tablero->getMap());
		//tablero->print();				
	}

	if(tecla == KEY_RIGHT)
	{
		pacman->movimiento(0, 1, tablero->getMap());
		//tablero->print();	
	}
	tablero->print();
	tecla = getch();
	}
}

void juego(Pacman * pacman, Fantasma* F, Tablero * tablero) // La función juego es la función principal
{
	
	int tecla;
	thread thread1 (esperar,pacman,tablero);//esto crea la thread
	while(/*(pacman.getX() != F1.getX()) or (pacman.getY() != F1.getY())*/true)//cuando este en azul hay que cambiar
	{	
		
		if (tablero->ganar())
		{
			break;
		}
		//para la salida de los fantasmas

		for (int i = 0; i < 3; i++)
		{
			F[i].setContador();
		 	if (F[i].getContador() > F[i].getSalida())
				F[i].movimiento(tablero->getMap(), *pacman);
		}
		tablero->print();
		usleep(599999); //controla la velicidad de los fantasmas
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


	juego(&pacman, fantasmas, &tablero); 
	
	endwin();
	return 0;

}
