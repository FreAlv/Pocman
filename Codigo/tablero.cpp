#include <iostream>
#include "tablero.h"

using namespace std; //borrar cuando ponga ncurses

Tablero::Tablero(int *mapa) 
{	
	int cont=0; //21x18

	map = new int* [22];
	for (int i = 0; i < 22; i++)
		map[i] = new int[19];

	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			map[i][j] = mapa[cont];
			cont++;
		}
	}
}

void Tablero::print()
{
	int f = 22;
	int c = 19;

	//los cout son probisionales hasta que metamos ncurses, con ncurses usamos printw
	cout << endl << endl;
	for (int i = 0; i < f; i++)
	{ 
		cout << "                                                 "; 
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] == 1) cout << "[]";
			else if (map[i][j] == 0) cout << "  ";
			else if (map[i][j] == 3) cout << "C3";
			else if (map[i][j] == 2) cout << "O<";
		}
		cout << endl;
	}
}