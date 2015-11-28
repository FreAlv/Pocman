#include "controljuego.h"
#include <ncurses.h>
#include <unistd.h>

ControlJuego::ControlJuego(int numNiveles)
{
	puntuacion = 0;
	vidas = 3;
	nivel = 1;
	this->numNiveles = numNiveles;
	
	modoAzul = false;
	
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
		wrefresh(pantallaJuego);
		usleep(3000000);
		//?INICIAR UN NUEVO MAPA,PACMAN Y FANTAMAS
	}
	else
	{
		mvwprintw(pantallaJuego,8,15, "GANASTE");
		mvwprintw(pantallaJuego,12,9, "Presiona una tecla ");
		mvwprintw(pantallaJuego,13,8, "para regresar al menu");
		wrefresh(pantallaJuego);
		
		int esperar = getch();
		
		wclear(pantallaJuego); //Borra contenido de la pantalla juego y datos
		wclear(pantallaDatos);
		wrefresh(pantallaJuego);
		wrefresh(pantallaDatos);		
	}
	
	
}

void ControlJuego::perder()
{
	--vidas;
	puntuacion-=500;
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
	int esperar = getch();
		
}


void ControlJuego::printDatos()
{
	mvwprintw(pantallaDatos,4,4,"PUNTUACION");
	mvwprintw(pantallaDatos,5,5,"%i",puntuacion);//luego completo los 000
	mvwprintw(pantallaDatos,10,7,"VIDAS");
	mvwprintw(pantallaDatos,11,10,"%i",vidas);
	wrefresh(pantallaDatos);
}





