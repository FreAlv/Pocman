#ifndef TABLERO_H
#define TABLERO_H

class Tablero
{
	int** map;
public:
	Tablero(int *mapa);
	void print();
	int** getMap(){ return map; }
};

#endif // TABLERO_H