#pragma once

#include "PuntosCartesianos.h"
#include "freeglut.h"

class BONUS
{
private:
	float lado;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	PUNTOSCARTESIANOS POSICION;

public:
	BONUS(float ix = 0.0f, float iz = 0.0f);
	virtual ~BONUS();
	// Funcion principal del dibujo del bonus
	void DIBUJA();
	
	PUNTOSCARTESIANOS getPos();

	friend class INTERACCIONES;
};

