//Zona de #includes.
#pragma once
#include "PuntosCartesianos.h"
#include "freeglut.h"

//Fin zona #includes.

/*Esta clase es heredada de la clase PuntosCartesianos, de esta forma tenemos los atributos x,y,z heredados y privados
  por lo que solo podemos acceder a ellos con los metodos publicos especificados en la clase antes mencionada.
*/

class Jugador //: public PuntosCartesianos 
{
public:
	Jugador(); //Declaracion del constructor por defecto.
	~Jugador(); //Declaracion del destructor por defecto.

	PuntosCartesianos POSICION;
	PuntosCartesianos VELOCIDAD;

	char DIRECCION;
	char PARADA;

	void Dibuja();

	void SetVel(float vx, float vz);

	void SetPos(float px, float py, float pz);

	void Mueve(float t);
};
