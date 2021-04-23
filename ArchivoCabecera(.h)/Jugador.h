#pragma once
//Zona de #includes.
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

	PuntosCartesianos posicion;
	PuntosCartesianos velocidad;

	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;

	void Dibuja(); //Metodo encargado del dibujado del personaje.
	void Mueve( float t); //Metodo encargado de mover el personaje mediante las teclas a,d,w,s.
	void SetVel(float vx, float vz);
	PuntosCartesianos getPos();

	void tecla(unsigned char key);
};

