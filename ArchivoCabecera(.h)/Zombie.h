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

	ZOMBIE();
	~ZOMBIE();

	void DIBUJA (void);
	void MUEVE(void);


	friend class MUNDO;
	friend class INTERACCIONES;

};

