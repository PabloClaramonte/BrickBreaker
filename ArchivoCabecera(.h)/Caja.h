#include "Pared.h"
#include "freeglut.h"

class Caja
{
public:
	Caja();
	virtual ~Caja();

	void Dibuja();

	//Paredes que delimitan la caja 
	Pared Norte; 
	Pared Sur;
	Pared Izquierda;
	Pared Derecha;
	Pared Suelo;
};

