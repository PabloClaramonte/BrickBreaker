#pragma once

#include "PuntosCartesianos.h"
#include "ObjetoMovil.h"
#include "freeglut.h"

class BONUS: public OBJETOMOVIL
{
private:
	float lado;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;

public:
	BONUS();
	virtual~BONUS();
	// Funcion principal del dibujo del bonus
	void DIBUJA();
	void MUEVE(float t);

	void SetPos(float ix, float iz);
	void SetVel(float vx, float vz);

};

