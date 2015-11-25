#ifndef TABLERO_H
#define TABLERO_H

class Tablero
{
	int** map;
	int Filas;
	int Columnas;
public:
	Tablero(int *mapa);
	void print();
	int** getMap(){ return map; }
	bool ganar();
};

#endif // TABLERO_H