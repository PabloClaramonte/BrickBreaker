#include "PuntosCartesianos.h"
#include <stdlib.h>
#include "freeglut.h"

class Bonus
{
public: 
	float lado;
	Bonus();
	virtual ~Bonus();
	PuntosCartesianos posicion; //Aparece cuando muere un zombie con una cierta probabilidad (20%?)
	void Dibuja();
};

