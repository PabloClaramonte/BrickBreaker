#pragma once

#include <PuntosCartesianos.h>
#include <freeglut.h>
#include <ObjetoMovil.h>

class DISPARO : public OBJETOMOVIL
{

private: 
	PUNTOSCARTESIANOS POSICION;
	PUNTOSCARTESIANOS VELOCIDAD;
public:

	DISPARO();
	DISPARO(float x = 0.0f, float z = 0.0f, float vx = 0.0f, float vz = 0.0f);
	~DISPARO();

	void DIBUJA(void);
	void MUEVE(float t);
	void SetVel(float vx, float vz);

	

	friend class MUNDO;
	friend class INTERACCIONES;
};

