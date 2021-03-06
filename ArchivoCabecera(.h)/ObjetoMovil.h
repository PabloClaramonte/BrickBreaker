#pragma once
#include "ETSIDI.h"

//CLASE ABSTRACTA QUE ENGLOBA LAS FUNCIONES MUEVE Y DIBUJA DE LOS OBJETOS M�VILES JUGADOR, ZOMBIE Y DISPARO.
class OBJETOMOVIL
{
protected:
	PUNTOSCARTESIANOS POSICION;
	PUNTOSCARTESIANOS VELOCIDAD;
	float ANGULO;
	float velocidad; //Atributo encargado de saber en cuantas unidades se incrementa la posicion del objeto cada ciclo de 25ms.
public:
	OBJETOMOVIL() { velocidad = 0.0f; }
	virtual ~OBJETOMOVIL() {}; //Importante que el destructor sea virtual para enlace din�mico.

	//Funciones virtuales puras:
	virtual void MUEVE(float t) = 0;
	virtual void DIBUJA() = 0;
};

