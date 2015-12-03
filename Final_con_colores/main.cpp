
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



void esperar(int* tecla, Pacman *pacman, std::vector<Fantasma> F, Tablero *tablero, ControlJuego *control)
{

	while(control->pasarNivel() and control->getVidas() > 0)
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
		
		tablero->print(*control);
		*tecla = getch();
	}
	
}
void juego(Pacman pacman, std::vector<Fantasma> F, Tablero tablero, ControlJuego* control) // La función juego es la función principal
{	
	int tecla;

	std::thread thread1 (esperar, &tecla, &pacman, F, &tablero, control);//esto crea el thread
	
	control->printDatos();
	while(true)
	{	
		if (control->getVidas() > 0)
		{
			tablero.print(*control);
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
				control->ganar();
				if (control->pasarNivel()) // Para pasar de nivel
				{
					tablero.restablecerMapa();
					for (int i = 0; i < 4; i++)
						F[i].posInicial(tablero.getMap());
					pacman.posInicial(tablero.getMap());
					tablero.print(*control);
				}
				else
				{
					thread1.detach();//elimina los threads
					break;			
				}
			}

			tablero.newVida();

			//Movimiento de fantasmas:		
			if (control->getmodoAzul() == false)
			{
				for (int i = 0; i < 4; i++)
				{
					F[i].movimiento(tablero.getMap(), pacman);

					if (F[i].fComeP(tablero.getMap(), pacman)) //cuando el fantasma come al pacman
					{
						tablero.print(*control);	//para ver que el fantasma come al pacman
						for (int j = 0; j < 4; j++)
						{
							F[j].posInicial(tablero.getMap());
						}
						pacman.posInicial(tablero.getMap());
						control->perder();	
						break;
					}
					tablero.print(*control);
				}	

				usleep(control->getVelocidad()); //controla la velicidad de los fantasmas
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
						
						tablero.print(*control);
					}
					
					usleep(control->getVelocidad() + 109999); // La velocidad de los fantasmas es mas lenta al estar azules
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
	initscr();// Inicia ncurses
	start_color();
	clear();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);

	int mapa[]={ //22 x 19 //Pacman: 16,09 (x,y)
      //0  1  2  3  4  5  6  7  8  9 10         		
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 2, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 2, 1,
		1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1,
		1, 1, 1, 1, 0, 1, 9, 9, 9, 9, 9, 9, 9, 1, 0, 1, 1, 1, 1,
		1, 1, 1, 1, 0, 1, 9, 1, 1, 1, 1, 1, 9, 1, 0, 1, 1, 1, 1,
		9, 9, 9, 9, 0, 0, 9, 1, 9, 9, 9, 1, 9, 0, 0, 9, 9, 9, 9,
		1, 1, 1, 1, 0, 1, 9, 1, 1, 1, 1, 1, 9, 1, 0, 1, 1, 1, 1,
		1, 1, 1, 1, 0, 1, 9, 9, 9, 9, 9, 9, 9, 1, 0, 1, 1, 1, 1,
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
		
	//Inicio de colores:
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLUE);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
		
	std::vector<const char*> menuOpciones {"Jugar", "Controles", "Creditos", "Salir"};
	Menu menu(menuOpciones);
	
	ControlJuego control(3); // le mandas como parámetro el número de niveles que quieres
	
	Tablero tablero(mapa);
	Pacman pacman(16, 9, "0<", tablero.getMap());
	//Fantasma* fantasmas;
	//fantasmas = new Fantasma[4];
	std::vector<Fantasma> fantasmas;
	fantasmas.push_back(Fantasma(8, 9, "=3", tablero.getMap(), 0));
	fantasmas.push_back(Fantasma(10, 8, "=3", tablero.getMap(), 5));
	fantasmas.push_back(Fantasma(10, 9, "=3", tablero.getMap(), 10));
	fantasmas.push_back(Fantasma(10, 10, "=3", tablero.getMap(), 15));
	

	while (true)
	{
		menu.usarMenu(control.getPantMenu());
		if (menu.getOpcion() == 0)
		{
			juego(pacman, fantasmas, tablero, &control);
			control.reiniciar();
			tablero.restablecerMapa();
			pacman.posInicial(tablero.getMap());
			for (int i = 0; i < 4; i++)
				fantasmas[i].posInicial(tablero.getMap());
			
			wclear(control.getPantJuego());
			wrefresh(control.getPantJuego());
		}
		if (menu.getOpcion() == 1)
			menu.printControles(control.getPantMenu());
		if (menu.getOpcion() == 2)
			menu.printCreditos(control.getPantMenu());
		if (menu.getOpcion() == 3)
			break;	
	}	
	endwin();
	return 0;

}
