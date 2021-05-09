#include "Interaccion.h"

bool Interaccion::AlcanceDisparo(Disparo BALA, Jugador HEROE)
{
	float distancia = sqrt((BALA.POSICION.X - HEROE.POSICION.X) * (BALA.POSICION.X - HEROE.POSICION.X)+(BALA.POSICION.Z - HEROE.POSICION.Z) * (BALA.POSICION.Z - HEROE.POSICION.Z));

	if (distancia ==50)
	{
		return true;
	}
	else if (distancia == 0)
	{
		return false;
	}
}


