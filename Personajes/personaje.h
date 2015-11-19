#ifndef PERSONAJE_H
#define PERSONAJE_H

class Personaje{
private:
	int x, y;
	int identificador;
	char img;
	
public:
	virtual bool rev_pared(int** map, int movX, int movY) = 0;
	virtual void void movimiento(bool pared, int movX, int movY) = 0;
	void getImg(){ return img; }
	void getIdentificador(){ return identificador; }
	int getX(){ return x; }
	int getY(){ return y; }
};

#endif // PERSONAJE_H
