
#include <ncurses.h>
#include <thread>
#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>

#include "pacman.h"
#include "tablero.h"
#include "fantasma.h"
#include "menu.h"
#include "controljuego.h"

using namespace std;

void esperar(int* tecla, Pacman *pacman, Fantasma* F, Tablero *tablero, ControlJuego *control)
{

	while(!tablero->ganar())
	{	
		if (control->getVidas() == 0)
		{
			break;
		}

		if(*tecla == KEY_UP)
		{ 	
			pacman->movimiento(-1, 0, tablero->getMap(), control);
		}
		
		if(*tecla == KEY_DOWN) 
		{	
			pacman->movimiento(1,0, tablero->getMap(), control);
		}
		
		if(*tecla == KEY_LEFT)
		{
			pacman->movimiento(0, -1, tablero->getMap(), control);			
		}
		
		if(*tecla == KEY_RIGHT)
		{
			pacman->movimiento(0, 1, tablero->getMap(), control);
		}
		if(*tecla == 'q') 
			break;
		
		tablero->print(control->getPantJuego());
		*tecla = getch();
	}
	
}
void juego(Pacman pacman, Fantasma* F, Tablero tablero, ControlJuego* control) // La función juego es la función principal
{	
	int tecla;

	thread thread1 (esperar, &tecla, &pacman, F, &tablero, control);//esto crea la thread

	while(true)
	{	
		if (control->getVidas() > 0)
		{
			tablero.print(control->getPantJuego());
			if (tecla == 'q') //es para salir
			{
				thread1.detach();
				wclear(control->getPantJuego());
				wclear(control->getPantDatos());
				wrefresh(control->getPantJuego());
				wrefresh(control->getPantDatos());
				break;
			}

			if (tablero.ganar())
			{
				thread1.detach();//elimina los threads
				control->ganar();
				break;
			}

			//Movimiento de fantasmas:		
			if (control->getmodoAzul() == false)
			{
				for (int i = 0; i < 4; i++)
				{
					F[i].movimiento(tablero.getMap(), pacman);

					if (F[i].fComeP(tablero.getMap(), pacman)) //cuando el fantasma come al pacman
					{
						tablero.print(control->getPantJuego());	//imprime el mapa
						control->perder();	
						for (int j = 0; j < 4; j++)
						{
							F[j].posInicial(tablero.getMap());
						}
						pacman.posInicial(tablero.getMap());
						break;
					}
					tablero.print(control->getPantJuego());
				}	
				
				usleep(599999); //controla la velicidad de los fantasmas
			}
		
			else
			{
				for (int j = 0; j < 10; j++)
				{
					for (int i = 0; i < 4; i++)
					{
						F[i].mAzul(tablero.getMap(), pacman);
						for(int k = 0; k < 4; k++)
							F[k].regresarCaja(tablero.getMap(), pacman);
						
						tablero.print(control->getPantJuego());
					}
					
					usleep(659999);
				}
				control->setmodoAzul(false);
			}
		}

		else
		{
			thread1.detach();//elimina los threads
			break;
		}
	}
}

int main() 
{
	initscr();// Todo esto es del ncurses, luego irá en una clase propia
	clear();
	//start_color(); // colores
	noecho();						
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);

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
		1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1,
		1, 1, 1, 1, 0, 0, 0, 1, 9, 9, 9, 1, 0, 0, 0, 1, 1, 1, 1, //10
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
		
	std::vector<const char*> menuOpciones {"Jugar", "Controles", "Creditos", "Salir"};
	Menu menu(menuOpciones);
	
	ControlJuego control(1); // le mandas como parámetro el número de niveles que quieres
	
	while (true)
	{
		menu.usarMenu(control.getPantMenu());
		if (menu.getOpcion() == 0)
		{
			
			Tablero tablero(mapa);
			Pacman pacman(16, 9, "0<", tablero.getMap());
			Fantasma* fantasmas;
			fantasmas = new Fantasma[4];
			*(fantasmas + 0) = Fantasma(8, 9, "=3", tablero.getMap(), 0);
			*(fantasmas + 1) = Fantasma(10, 8, "=3", tablero.getMap(), 5);
			*(fantasmas + 2) = Fantasma(10, 9, "=3", tablero.getMap(), 15);
			*(fantasmas + 3) = Fantasma(10, 10, "=3", tablero.getMap(), 25);
			wclear(control.getPantMenu());
			wrefresh(control.getPantMenu());
			juego(pacman, fantasmas, tablero, &control);
			control.reiniciar();
		}
		if (menu.getOpcion() == 1)
			mvwprintw(control.getPantMenu(),0,0 , "hola");
		if (menu.getOpcion() == 2)
			mvwprintw(control.getPantMenu(),0,0, "chau");
		if (menu.getOpcion() == 3)
			break;	
	}	
	endwin();
	return 0;

}
