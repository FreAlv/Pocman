
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void perdiste(){
	cout << endl;
  cout << "________________________________________________________________________________________________________________________________________________" << endl;
	cout << "________________________________________________________________PERDISTE________________________________________________________________________" << endl;
	cout << "________________________________________________________________________________________________________________________________________________" << endl;
  cout << endl;
}

class Fantasma
{
	int Cordenada_F;
	int Cordenada_C;
public:
	Fantasma();
	~Fantasma();
	int GetCordenada_F(){return Cordenada_F; }
	int GetCordenada_C(){return Cordenada_C; }

};

int** crearMatriz()
{
	int f = 22;
	int c = 19;
    srand (time(NULL));
    int** m = new int*[f];
    for(int i=0; i<f;i++)
    {
        (*(m+i)) = new int[c];
    }
    int cont=0; //21x18

    int caca[]={ //0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18
    			   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,//0
    			   1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,//1
    			   1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1,//2
    			   1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1,//3
    			   1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,//4
    			   1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1,//5
    			   1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,//6
    			   1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1,//7
    			   1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1,//8
    			   1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1,//9
    			   1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1,//10
    			   1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1,//11
    			   1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1,//12  12x9
    			   1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1,//13
    			   1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,//14
    			   1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1,//15
    			   1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1,//16
    			   1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1,//17
    			   1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,//18
    			   1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1,//19
    			   1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,//20
    			   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};//21
    
    for(int i=0; i<f; i++)
    {
        for (int j=0; j<c; j++)
        {	
           	*((*(m+i))+j) = caca[cont];
            cont++;
        }
    }

       // m[rand()%f][rand()%c]=1;

    return m;
}

void print(int** m, int f, int c)
{
	cout << endl << endl;
	for (int i = 0; i < f; i++)
	{ 
		cout << "                                               "; 
		for (int k = 0; k < c; k++)
		{
			cout << m[i][k] << " ";
		}
		cout << endl;
	}
}

void busca(int** m, int &cordenada_F_POC, int &cordenada_C_POC, int &cordenada_F_FAN, int &cordenada_C_FAN)
{

	if ((cordenada_C_POC <= cordenada_C_FAN) 
	{	
		if (m[cordenada_F_FAN][cordenada_C_FAN-1] != 1))
		{
			m[cordenada_F_FAN][cordenada_C_FAN] = 0;
			cordenada_C_FAN -= 1;
			m[cordenada_F_FAN][cordenada_C_FAN] = 3;
			cout << "CACA 1" << endl;
			return;
	}

	else if ((cordenada_C_POC >= cordenada_C_FAN) 
	{
		if (m[cordenada_F_FAN][cordenada_C_FAN+1] != 1))
		{	
			m[cordenada_F_FAN][cordenada_C_FAN] = 0;
			cordenada_C_FAN += 1;
			m[cordenada_F_FAN][cordenada_C_FAN] = 3;
			cout << "CACA 2" << endl;
			return;
		}
	}

	//cout << "cordenada_F_POC " << cordenada_F_POC << " > " << "cordenada_F_FAN " << cordenada_F_FAN << endl;
	else if ((cordenada_F_POC >= cordenada_F_FAN)
	{
		if (m[cordenada_F_FAN +1][cordenada_C_FAN] != 1))
		{	
			m[cordenada_F_FAN][cordenada_C_FAN] = 0;
			cordenada_F_FAN += 1;
			m[cordenada_F_FAN][cordenada_C_FAN] = 3;		
			cout << "CACA 3" << endl;
			return;
	}

	else if ((cordenada_F_POC <= cordenada_F_FAN) 
	{
		if (m[cordenada_F_FAN -1][cordenada_C_FAN] != 1))
		{
			m[cordenada_F_FAN][cordenada_C_FAN] = 0;
			cordenada_F_FAN -= 1;
			m[cordenada_F_FAN][cordenada_C_FAN] = 3;		
			cout << "CACA 4" << endl;
			return;
		}
	}
}

void mover(char x, int** m, int &cordenada_F_POC, int &cordenada_C_POC)
{
	if (x == 'w')
	{
		cout << "ecwenfoewifo 1" << endl << endl;
		if (m[cordenada_F_POC -1][cordenada_C_POC] == 0)
		{
			cout << "ecwenfoewifo 3" << endl << endl;
			m[cordenada_F_POC][cordenada_C_POC] = 0;
			cordenada_F_POC -= 1;
			m[cordenada_F_POC][cordenada_C_POC] = 2;
		}
	}

	if (x == 's')
	{
		cout << "ecwenfoewifo 2" << endl << endl;
		if (m[cordenada_F_POC +1][cordenada_C_POC] == 0)
		{
			cout << "ecwenfoewifo 4" << endl << endl;
			m[cordenada_F_POC][cordenada_C_POC] = 0;
			cordenada_F_POC += 1;
			m[cordenada_F_POC][cordenada_C_POC] = 2;
		}
	}

	if (x == 'd')
	{
		if (m[cordenada_F_POC][cordenada_C_POC+1] == 0)
		{
			cout << "   derecha " << endl << endl;
			m[cordenada_F_POC][cordenada_C_POC] = 0;
			cordenada_C_POC += 1;
			m[cordenada_F_POC][cordenada_C_POC] = 2;
		}
	}

	if (x == 'a')
	{
		if (m[cordenada_F_POC][cordenada_C_POC-1] == 0)
		{
			cout << "   isquierda " << endl << endl;
			m[cordenada_F_POC][cordenada_C_POC] = 0;
			cordenada_C_POC -= 1;
			m[cordenada_F_POC][cordenada_C_POC] = 2;
		}
	}
}

int main()
{
	int** poc = crearMatriz();
	int C_F_P, C_C_P, C_F_F1, C_C_F1, C_F_F2, C_C_F2;
	int contador = 0;
	C_F_P = 12;
	C_C_P = 9;
	C_F_F1 = 10;
	C_C_F1 = 9;
	C_F_F2 = 10;
	C_C_F2 = 8;
	poc[C_F_P][C_C_P] = 2;
	poc[C_F_F1][C_C_F1] = 3;
	poc[C_F_F2][C_C_F2] = 3;

	print(poc, 22, 19);

	while (((C_F_P != C_F_F1) or (C_C_P != C_C_F1)) and ((C_F_P != C_F_F2) or (C_C_P != C_C_F2)))
	{
		char x;
		cout << "mover "; cin  >> x;
		mover(x, poc, C_F_P, C_C_P);
		busca(poc, C_F_P, C_C_P, C_F_F1, C_C_F1);	
		if (contador > 9)
		{
			busca(poc, C_F_P, C_C_P, C_F_F2, C_C_F2);
		}

		print(poc, 21, 18);
		contador++;		
	}
	perdiste();

	return 0;
}


