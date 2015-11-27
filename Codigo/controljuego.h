#ifndef CONTROLJUEGO_H
#define CONTROLJUEGO_H

#include <ncurses.h>

class ControlJuego
{
	int puntuacion;
	int vidas;
	int nivel;
	int numNiveles;
	int velocidad;
	WINDOW *pantallaJuego;
	WINDOW *pantallaMenu;
	WINDOW *pantallaDatos;
	
public:
	ControlJuego(int numNiveles);
	void ganar();
	void perder();
	void printDatos();
	int getVidas() { return vidas; }
	WINDOW *getPantJuego() { return pantallaJuego; }
	WINDOW *getPantMenu() { return pantallaMenu;  }
	WINDOW *getPantDatos() { return pantallaDatos;  }
};

#endif // CONTROLJUEGO_H
