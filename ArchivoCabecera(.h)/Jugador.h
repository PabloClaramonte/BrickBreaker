//Zona de #includes.
#pragma once
#include "PuntosCartesianos.h"
#include "freeglut.h"
#include <ObjetoMovil.h>
#include "ETSIDI.h"
//Fin zona #includes.

class JUGADOR : public OBJETOMOVIL
{
private:
	char WSAD;//Atributo encargado de conocer la direccion en la cual se mueve el JUGADOR o si comienza a disparar.
	char PREWSAD;//Atributo encargado de conocer la ultima direccion del JUGADOR, antes de pararse para disparar.
	//PUNTOSCARTESIANOS POSICION;//Atributo encargado de conocer la posicion del jugador en el mapa.
	//PUNTOSCARTESIANOS VELOCIDAD;
public:
	


	
	//Constructor con argumentos (sustituye al costructor sin argumentos para poder inicializar en menos líneas):
	JUGADOR();

	//Destrcutor por defecto.
	~JUGADOR();
	
	//Metodo encargado del dibujado del personaje.
	void DIBUJA(void);

	void MUEVE(float t);
	PUNTOSCARTESIANOS getPos();

	void setvel(float vx, float vz);

	friend class INTERACCIONES;
	friend class MUNDO;
};
