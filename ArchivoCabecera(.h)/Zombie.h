#pragma once

#include <PuntosCartesianos.h>

class ZOMBIE
{

private:

	bool VIVO;

	float VELOCIDAD;
	float ANGULO;

	PUNTOSCARTESIANOS POSICION;

public:

	ZOMBIE(); //Constructor sin argumentos
	~ZOMBIE();

	void DIBUJA (void);
	void MUEVE(void);

	ZOMBIE(float x = 0.0f, float z = 0.0f, float v = 0.0f);

	friend class MUNDO;
	friend class INTERACCIONES;

};

