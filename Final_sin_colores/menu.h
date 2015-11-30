#ifndef MENU_H
#define MENU_H

#include <vector>
#include <ncurses.h>

class Menu
{
	std::vector<const char*> opciones;
	int numOpciones;
	int seleccionado;
	int opcion;
	void printOpciones(WINDOW *w);
public:
	Menu(std::vector<const char*> opciones);
	void usarMenu(WINDOW *w);
	int getOpcion() {return opcion;}
};

#endif // MENU_H
