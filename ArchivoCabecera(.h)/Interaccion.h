#pragma once

#include "Jugador.h"
#include "Disparo.h"
#include "Caja.h" 
#include <math.h>


class Interaccion
{
public:
	static bool AlcanceDisparo(Disparo BALA, Jugador HEROE);
	static void Rebote(Jugador& HEROE, Caja CAJA);
};

