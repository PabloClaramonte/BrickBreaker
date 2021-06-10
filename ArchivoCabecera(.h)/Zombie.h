#pragma once

#include <PuntosCartesianos.h>
#include <ObjetoMovil.h>

class ZOMBIE : public OBJETOMOVIL
{
private:

	float VELOCIDAD;
	float ANGULO;

	PUNTOSCARTESIANOS POSICION;

public:

	ZOMBIE(); //Constructor sin argumentos
	ZOMBIE(float x = 0.0f, float z = 0.0f, float v = 0.0f);
	~ZOMBIE();

	void DIBUJA (void);
	void MUEVE(float t);

	

	friend class MUNDO;
	friend class INTERACCIONES;

};

