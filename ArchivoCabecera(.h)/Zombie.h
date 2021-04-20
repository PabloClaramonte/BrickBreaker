#include "PuntosCartesianos.h"
#include "freeglut.h"

class Zombie
{
public:

	Zombie();
	virtual ~Zombie();

	void Dibuja();
	void Mueve(float t);

	//Velocidad, posición y aceleración del zombie 
	PuntosCartesianos posicion;
	PuntosCartesianos velocidad; //(aumentará por cada nivel)
	//PuntosCartesianos aceleracion; si queremos que el zombie varíe su velocidad.
};

