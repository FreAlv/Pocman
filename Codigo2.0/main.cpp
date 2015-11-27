
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

void esperar(bool *h, Pacman *pacman, Fantasma* F, Tablero *tablero, ControlJuego *control)
{
	
	int tecla = getch();
	while(true)
	{
		if (pacman->getPocisionActual() == 0)//para las bolas pequeñas
		{	
			control->setPuntuacion();
			control->printDatos(); //MOVER ESTO A OTRO LADO, MOVER A DONDE SE LLAME A LA FUNCIÓN AUMENTAR PUNTOS
		}

		if (h)//para las bolas grandes Tiene problemas al comer fantasmas 
		{
			for (int i = 0; i < 4; ++i)
			{
				F[i].regresarCaja(tablero->getMap(), *pacman);
			}
		}
	
		if(tecla == KEY_UP)
		{ 	
			pacman->movimiento(-1, 0, tablero->getMap());
		}
		
		if(tecla == KEY_DOWN) 
		{	
			pacman->movimiento(1,0, tablero->getMap());
		}
		
		if(tecla == KEY_LEFT)
		{
			pacman->movimiento(0, -1, tablero->getMap());			
		}
		
		if(tecla == KEY_RIGHT)
		{
			pacman->movimiento(0, 1, tablero->getMap());
		}
		if(tecla == 'q') 
			break;
		
		tablero->print(control->getPantJuego());
		tecla = getch();
	}
	
}

//es para las bolas grandes
void puntos(bool *h, Pacman *pacman, Fantasma* F,Tablero *tablero, ControlJuego *control)
{
	while (true)
	{
		if (pacman->getPocisionActual() == 2)
			*h = true;
	}
}

void juego(Pacman * pacman, Fantasma* F, Tablero *tablero, ControlJuego *control) // La función juego es la función principal
{	
	int tecla; bool t2 = false;

	thread thread1 (esperar, &t2, pacman, F, tablero, control);//esto crea la thread
	thread thread2 (puntos, &t2, pacman, F, tablero, control);//para las bolas grandes

	while(/*(pacman.getX() != F1.getX()) or (pacman.getY() != F1.getY())*/true)//cuando este en azul hay que cambiar
	{	
		
		if (tablero->ganar())
		{
			thread1.detach();//elimina los threads
			thread2.detach();
			control->ganar();
			break;
		}

		if (t2)//es para las bolas grandes
		{
			for (int i = 0; i < 10; i++)
			{
				for (int i = 0; i < 4; i++)
				{
					F[i].mAzul(tablero->getMap(), *pacman);
					//F[i].regresarCaja(tablero->getMap(), *pacman);
				}
				tablero->print(control->getPantJuego());
				usleep(399999);
			}
			t2 = false;
		}
		
		//para la salida de los fantasmas
		for (int i = 0; i < 4; i++)
		{
			F[i].setContador();
		 	if (F[i].getContador() >= F[i].getSalida())
				F[i].movimiento(tablero->getMap(), *pacman);
		}
		tablero->print(control->getPantJuego());
		
		usleep(599999); //controla la velicidad de los fantasmas
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
		
	std::vector<const char*> menuOpciones {"Jugar", "Controles", "Creditos", "Salir"};
	Menu menu(menuOpciones);
	
	ControlJuego control(1); // le mandas como parámetro el número de niveles que quieres
	
	Tablero tablero(mapa);
	Pacman pacman(16,9, "0<", tablero.getMap());
	
	Fantasma* fantasmas;
	fantasmas = new Fantasma[4];
	*(fantasmas + 0) = Fantasma(8, 9, "=3", tablero.getMap(), 0);
	*(fantasmas + 1) = Fantasma(10, 8, "=3", tablero.getMap(), 5);
	*(fantasmas + 2) = Fantasma(10, 9, "=3", tablero.getMap(), 20);
	*(fantasmas + 3) = Fantasma(10, 10, "=3", tablero.getMap(), 40);
		
	while (true)
	{
		menu.usarMenu(control.getPantMenu());
		if (menu.getOpcion() == 0)
		{
			wclear(control.getPantMenu());
			wrefresh(control.getPantMenu());
			juego(&pacman, fantasmas, &tablero, &control);
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