#pragma once
#include "PuntosCartesianos.h"

#include <math.h>
#include "freeglut.h"

class Disparo
{
public:

	PuntosCartesianos POSICION;
	PuntosCartesianos VELOCIDAD;

	char DIRECCION;
	int TIEMPO;

	Disparo();
	~Disparo() {};

	void Dibuja(void);

	void SetPos(float posx, float posy, float posz);
	void SetVel(float vx, float vz);

	//void TiempoDisparo(Jugador& HEROE);

	void Mueve(float t);
	//int TiempoDisparo();

};

