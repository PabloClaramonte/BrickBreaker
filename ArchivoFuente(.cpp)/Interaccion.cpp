#include "Interaccion.h"

bool Interaccion::AlcanceDisparo(Disparo BALA, Jugador HEROE)
{
	float distancia = sqrt((BALA.POSICION.X - HEROE.POSICION.X) * (BALA.POSICION.X - HEROE.POSICION.X)+(BALA.POSICION.Z - HEROE.POSICION.Z) * (BALA.POSICION.Z - HEROE.POSICION.Z));

	if (distancia == 50)
	{
		return true;
	}
	else if (distancia == 0)
	{
		return false;
	}
}

void Interaccion::Rebote(Jugador& HEROE, Caja CAJA)
{
	float xmax = CAJA.Derecha.LIMITE1.X;
	float xmin = 0.0f;
	float zmax = CAJA.Sur.LIMITE1.Z;
	float zmin = 0.0f;
	if (HEROE.POSICION.X > xmax) {
		HEROE.POSICION.X = xmax;
		HEROE.VELOCIDAD.X = 0.0;
	}
	if (HEROE.POSICION.X < xmin) {
		HEROE.POSICION.X = xmin;
		HEROE.VELOCIDAD.X = 0.0;
	}
	if (HEROE.POSICION.Z > zmax)
		HEROE.POSICION.Z = zmax;
	if (HEROE.POSICION.Z < zmin)
		HEROE.POSICION.Z = zmin;
}


