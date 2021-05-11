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

	ZOMBIE()
	{
		VIVO = true;

		POSICION.X = 0.0;
		POSICION.Y = 0.0;
		POSICION.Z = 0.0;
		VELOCIDAD = 0.0;
	};

	~ZOMBIE() {};

	void DIBUJA (void);
	void MUEVE(void);
	


	friend class MUNDO;
	friend class INTERACCIONES;

};

