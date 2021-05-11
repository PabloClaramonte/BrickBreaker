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

	DISPARO()
	{
		POSICION.X = 0.0;
		POSICION.Y = 0.0;
		POSICION.Z = 0.0;

		TIEMPODISPARO = 0;
	}

	~DISPARO() {};

	void DIBUJA(void);





	friend class MUNDO;
	friend class INTERACCIONES;

};

