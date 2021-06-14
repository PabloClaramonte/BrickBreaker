//Zona de #includes.
#pragma once
#include "PuntosCartesianos.h"
#include "freeglut.h"
#include <ObjetoMovil.h>

//Fin zona #includes.

using ETSIDI::SpriteSequence;

class JUGADOR : public OBJETOMOVIL
{
private:
	char WSAD;//Atributo encargado de conocer la direccion en la cual se mueve el JUGADOR o si comienza a disparar.
	char PREWSAD;//Atributo encargado de conocer la ultima direccion del JUGADOR, antes de pararse para disparar.
	SpriteSequence sprite;
	float radio;
public:
	//Constructor con argumentos (sustituye al costructor sin argumentos para poder inicializar en menos líneas):
	JUGADOR();

	//Destrcutor por defecto.
	~JUGADOR();

	//Metodo encargado del dibujado del personaje.
	void DIBUJA(void);

	void MUEVE(float t);


	void setvel(float vx, float vz);

	friend class INTERACCIONES;
	friend class MUNDO;
};
