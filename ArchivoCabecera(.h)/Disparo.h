#pragma once

#include <PuntosCartesianos.h>
#include <freeglut.h>

class DISPARO 
{

private: 

	int TIEMPODISPARO;
	int VELOCIDAD;

	char DIRECCION;

	PUNTOSCARTESIANOS POSICION;

public:

	DISPARO();
	~DISPARO();

	void DIBUJA(void);

	friend class MUNDO;
	friend class INTERACCIONES;
};

