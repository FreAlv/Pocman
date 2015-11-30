#ifndef TABLERO_H
#define TABLERO_H

#include <ncurses.h>

class Tablero
{
	int** map;
	int filas;
	int columnas;
	int** copyMap;
	
public:
	Tablero(int *mapa);
	void print(WINDOW *w);
	int** getMap(){ return map; }
	bool ganar();
	void restablecerMapa();

};

#endif // TABLERO_H