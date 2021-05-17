#pragma once

#include <math.h>

#include <Jugador.h>
#include <Tablero.h>
#include <Columna.h>
#include <Disparo.h>
#include <Zombie.h>

class INTERACCIONES
{
private:

public:
	//Funciones static porque es una función que queremos utilizar independientemente de que haya o no un objeto
	static void INTERACCION_JUGADOR_TABLERO(JUGADOR& HEROE, TABLERO SUELO);
	static void INTERACCION_JUGADOR_COLUMNA(JUGADOR& HEROE, COLUMNA _COLUMNA);
	static void INTERACCION_ZOMBIE_COLUMNA(ZOMBIE& MALO, COLUMNA _COLUMNA);
	static void INTERACCION_JUGADOR_DISPARO(JUGADOR& HEROE, DISPARO& BALA);
	static void INTERACCION_BALA_ZOMBIE(DISPARO& BALA, ZOMBIE& MALO);
	static void INTELIGENCIA_ARTIFICIAL_ZOMBIE(JUGADOR HEROE, ZOMBIE& MALO);
	static void INTERACCION_JUGADOR_TECLADO(JUGADOR& HEROE, unsigned char TECLA);
};



