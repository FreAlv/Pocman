#include <ncurses.h>
#include "pacman.h"
#include "tablero.h"
#include "fantasma.h"
#include <thread>
#include <iostream>
#include <vector>
#define TIEMPO 10

using namespace std;

vector<thread*> Ts;
void esperar(int* _tecla)
{
	system ("/bin/stty -icanon");
	int tecla = getch();
	*_tecla=tecla;
}

void juego(Pacman pacman, Tablero tablero) // La función juego es la función principal
{
	bool pared;
	Fantasma F1(10, 9, "=3", tablero.getMap());
	int tecla;
	int *ptr_tecla=&tecla;
	//cout<<tecla<<endl;
	while((pacman.getX() != F1.getX()) or (pacman.getY() != F1.getY()))//cuando este en azul hay que cambiar
	{	
		int tecla = getch();
		//Ts.push_back(new thread(esperar, ptr_tecla));	
		if(tecla == KEY_UP)  //KEY_LEFT
		{ 	
			pacman.setImg(">O");
			pared = pacman.rev_pared(tablero.getMap(),-1,0);
			if(pared) // este if es provisional
			{
				clear();
				pacman.movimiento(pared, -1, 0, tablero.getMap());
				//F1.movimiento(tablero.getMap(), pacman);
				tablero.print();			
			}
		}

		if(tecla == KEY_DOWN) //KEY_RIGHT
		{	
			pacman.setImg("O<");
			pared = pacman.rev_pared(tablero.getMap(),1,0);
			if(pared) // este if es provisional
			{
				clear();
				pacman.movimiento(pared,1,0, tablero.getMap());
				//F1.movimiento(tablero.getMap(), pacman);
				tablero.print();
			}
		}
		if(tecla == KEY_LEFT)
		{
			pacman.setImg("Ov");
			pared = pacman.rev_pared(tablero.getMap(),0, -1);
			if(pared) // este if es provisional
			{
				clear();
				pacman.movimiento(pared, 0, -1, tablero.getMap());
				tablero.print();				
			}
			//F1.movimiento(tablero.getMap(), pacman);
		}
		if(tecla == KEY_RIGHT)
		{
			pacman.setImg("On");
			pared = pacman.rev_pared(tablero.getMap(),0, 1);
			if(pared) // este if es provisional
			{
				pacman.movimiento(pared, 0, 1, tablero.getMap());
				clear();
				tablero.print();
			}
			
		}
		//F1.movimiento(tablero.getMap(), pacman);
		tablero.print();
		if(tecla == 'q') break;
        //Ts.clear();
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
	Pacman pacman(1,1, ">O", tablero.getMap());
	
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
