#include "PuntosCartesianos.h"
#include "freeglut.h"

class Zombie : public PuntosCartesianos
{
public:

	Zombie();
	~Zombie();

	void Dibuja();
	void Mueve(float t);
	void SetVel(float vx, float vz); //Asigna una velocidad al zombie.

	//Velocidad, posición y aceleración del zombie 
	PuntosCartesianos posicion;
	PuntosCartesianos velocidad; //(aumentará por cada nivel)
	
	//PuntosCartesianos getPos();
};

