#ifndef PERSONAJE_H
#define PERSONAJE_H

class Personaje
{
protected:
	int x, y;
	int copyX, copyY;
	int identificador;
	const char* img;
	virtual bool rev_pared(int movX, int movY, int** map) = 0;
public:
	Personaje(int x, int y, const char* img);
	
	virtual void posInicial(int** map) = 0;
	void movimiento(bool pared, int movX, int movY);
	const char* getImg(){ return img; }

	int getX(){ return x; }
	int getY(){ return y; }
	//void setImg(const char* _img){ img = _img; }
};

#endif // PERSONAJE_H

