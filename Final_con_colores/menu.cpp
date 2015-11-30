#include "menu.h"

#include <ncurses.h>
Menu::Menu(std::vector< const char* > opciones)
{
	this->opciones = opciones;
	numOpciones = opciones.size();
	seleccionado = 0;
}

void Menu::printOpciones(WINDOW *w)
{
	int y = 11;
	mvwprintw(w,9,37, "POCMAN" ); //80-24
	for(int i = 0; i < numOpciones; ++i)
	{	
		if(i == seleccionado) 
		{	wattron(w,A_REVERSE); //Resalta la opcion
			mvwprintw(w, y, 36, "%s", opciones[i]);
			wattroff(w,A_REVERSE);
		}
		else
			mvwprintw(w, y, 36, "%s", opciones[i]);
		++y;
	}
	wrefresh(w);
}

void Menu::usarMenu(WINDOW *w)
{
	int tecla;
	while (true)
	{
		printOpciones(w);
		opcion = -1;
		tecla = getch();
		if(tecla == KEY_UP)
		{ 	
			if (seleccionado == 0)
				seleccionado = numOpciones -1;
			else 
				--seleccionado;
		}
			
		if(tecla == KEY_DOWN) 
		{	
			if (seleccionado == numOpciones -1)
				seleccionado = 0;
			else
				++seleccionado;
		}
		if(tecla == 10)
		{
			opcion =seleccionado;
			wclear(w);
			wrefresh(w);
			break;
		}
		//? qué tenemos que hacer para que funcione con la funcion juego
		
	}
}

void Menu::printControles(WINDOW *w)
{
	
	mvwprintw(w, 4, 36,"Controles");
	mvwprintw(w, 7, 24, "Movimiento: Flechas direccionales");
	mvwprintw(w, 8, 31, "Salir del juego: q");
	mvwprintw(w, 9, 26, "Seleccionar una opcion: ENTER");
	
	mvwprintw(w,18,20, "Presiona una tecla para regresar al menu");
	
	wrefresh(w);
	int esperar = getch();
		
	wclear(w);
}

void Menu::printCreditos(WINDOW *w)
{

	mvwprintw(w, 7, 36,"Creditos");
	mvwprintw(w, 9, 31, "Fredy Alvarez Bejar");
	mvwprintw(w, 10, 30, "Juan Velasquez Malaga");
	
	mvwprintw(w,18,20, "Presiona una tecla para regresar al menu");
	
	wrefresh(w);
	int esperar = getch();
		
	wclear(w);
}






