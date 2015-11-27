#include "controljuego.h"
#include <ncurses.h>

ControlJuego::ControlJuego(int numNiveles)
{
	puntuacion = 0;
	vidas = 3;
	nivel = 1;
	this->numNiveles = numNiveles;
	
	pantallaJuego = newwin(22,38,1,3);
	pantallaMenu = newwin(0,0,0,0);
	pantallaDatos = newwin(22,19,1,45);
}

void ControlJuego::ganar()
{
	wclear(pantallaJuego);
	if (nivel < numNiveles)
	{
		++nivel;
		mvwprintw(pantallaJuego,11,15, "NIVEL %i", nivel);
	}
	else
	{
		mvwprintw(pantallaJuego,11,15, "GANASTE");
	}
	wrefresh(pantallaJuego);
	
}

void ControlJuego::perder()
{
	--vidas;
	wclear(pantallaJuego);
	mvwprintw(pantallaJuego,10,15, "PERDISTE");
	mvwprintw(pantallaJuego,11,5, "Te quedan %i vidas", vidas);
	if (vidas >0)
	{
		mvwprintw(pantallaJuego,12,2, "Presiona una tecla para continuar");
	}
	else
	{
		mvwprintw(pantallaJuego,12,9, "Presiona una tecla ");
		mvwprintw(pantallaJuego,13,8, "para regresar al menu");
	}
	wrefresh(pantallaJuego);
		
}


void ControlJuego::printDatos()
{
	mvwprintw(pantallaDatos,4,4,"PUNTUACION");
	mvwprintw(pantallaDatos,5,5,"%i",puntuacion);//luego completo los 000
	mvwprintw(pantallaDatos,10,7,"VIDAS");
	mvwprintw(pantallaDatos,11,10,"%i",vidas);
	wrefresh(pantallaDatos);
}




