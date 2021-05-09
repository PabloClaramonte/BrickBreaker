#pragma once
//#include "Disparo.h"
//#include "Jugador.h"
#include "Pared.h"
#include "Bonus.h"
#include "PuntosCartesianos.h"
#include "Interaccion.h"

class Mundo {
public:
	Caja CAJA;
	Jugador HEROE;
	Disparo BALA;
	Bonus BONUS;

	void Inicializa();
	void tecla(unsigned char key);
	void Dibuja();
	void DibujaEjes();
	void Mueve();

};
