#include "PuntosCartesianos.h"
#include "freeglut.h"

class Zombie
{
public:

	Zombie();
	virtual ~Zombie();

	void Dibuja();
	void Mueve(float t);

	//Velocidad, posici�n y aceleraci�n del zombie 
	PuntosCartesianos posicion;
	PuntosCartesianos velocidad; //(aumentar� por cada nivel)
	//PuntosCartesianos aceleracion; si queremos que el zombie var�e su velocidad.
};

