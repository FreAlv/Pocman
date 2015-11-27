#ifndef TABLERO_H
#define TABLERO_H

#include <ncurses.h>

class Tablero
{
	int** map;
	int filas;
	int columnas;
public:
	Tablero(int *mapa);
	void print(WINDOW *w);
	int** getMap(){ return map; }
	bool ganar();

};

#endif // TABLERO_H