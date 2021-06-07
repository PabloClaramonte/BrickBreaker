//Zona de #includes.
#pragma once
#include "PuntosCartesianos.h"
#include "freeglut.h"

#include "ETSIDI.h"
using ETSIDI::SpriteSequence;
//Fin zona #includes.

/*Esta clase es heredada de la clase PuntosCartesianos, de esta forma tenemos los atributos x,y,z heredados y privados
  por lo que solo podemos acceder a ellos con los metodos publicos especificados en la clase antes mencionada.
*/
class JUGADOR 
{
private:
	SpriteSequence sprite{ "imagenes/pangPlayer.png", 5 };
	char WSAD;//Atributo encargado de conocer la direccion en la cual se mueve el JUGADOR o si comienza a disparar.
	char PREWSAD;//Atributo encargado de conocer la ultima direccion del JUGADOR, antes de pararse para disparar.
	PUNTOSCARTESIANOS POSICION;//Atributo encargado de conocer la posicion del jugador en el mapa.
	PUNTOSCARTESIANOS VELOCIDAD;

public:
	//Constructor con argumentos (sustituye al costructor sin argumentos para poder inicializar en menos líneas):
	JUGADOR();

	//Destrcutor por defecto.
	~JUGADOR();
	
	//Metodo encargado del dibujado del personaje.
	void DIBUJA(void);

	void Mueve(float t);

	void setvel(float vx, float vz);

	friend class INTERACCIONES;
	friend class MUNDO;
};
