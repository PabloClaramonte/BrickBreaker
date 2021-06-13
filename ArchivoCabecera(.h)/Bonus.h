#pragma once

#include "PuntosCartesianos.h"
//#include "ObjetoMovil.h"
#include "freeglut.h"

class BONUS//: public OBJETOMOVIL
{
private:
	float lado;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	PUNTOSCARTESIANOS POSICION;

public:
	BONUS();
	virtual~BONUS();
	// Funcion principal del dibujo del bonus
	void DIBUJA();
	BONUS(float ix = 0.0f, float iz = 0.0f);

	//void SetPos(float ix, float iz);

};

