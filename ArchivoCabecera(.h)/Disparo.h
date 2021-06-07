#pragma once

#include <PuntosCartesianos.h>
#include <freeglut.h>

class DISPARO 
{

private: 
	PUNTOSCARTESIANOS POSICION;
	PUNTOSCARTESIANOS VELOCIDAD;
public:

	DISPARO();
	~DISPARO();

	void DIBUJA(void);
	void Mueve(float t);
	void SetVel(float vx, float vz);

	DISPARO(float x = 0.0f, float z = 0.0f, float vx = 0.0f, float vz = 0.0f);

	friend class MUNDO;
	friend class INTERACCIONES;
};

