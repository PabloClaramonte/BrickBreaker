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
	//Constructor por defecto
	JUGADOR();

	//Destrcutor por defecto.
	~JUGADOR();

	//Metodo encargado de dibujar el personaje.
	void DIBUJA(void);
	//Movimiento del personaje.
	void MUEVE(float t);
	//Asignción de velocidad del personaje.
	void setvel(float vx, float vz);

	friend class INTERACCIONES;
	friend class MUNDO;
};
