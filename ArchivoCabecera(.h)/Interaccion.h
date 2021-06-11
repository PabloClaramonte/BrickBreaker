#pragma once

#include <math.h>

#include <Jugador.h>
#include <Tablero.h>
#include <Columna.h>
#include <Disparo.h>
#include <Zombie.h>

class INTERACCIONES
{
public:
	//Funciones static porque es una función que queremos utilizar independientemente de que haya o no un objeto
	static bool INTERACCION_JUGADOR_COLUMNA(JUGADOR& HEROE, COLUMNA& _COLUMNA);
	static bool INTERACCION_JUGADOR_ZOMBIE(JUGADOR& HEROE, ZOMBIE& MALO);
	static void INTERACCION_JUGADOR_TABLERO(JUGADOR& HEROE, TABLERO& SUELO);

	static void INTERACCION_ZOMBIE_COLUMNA(ZOMBIE& MALO, COLUMNA& _COLUMNA);
	static void INTELIGENCIA_ARTIFICIAL_ZOMBIE(JUGADOR& HEROE, ZOMBIE& MALO);
	static void CHOQUE_ENTRE_ZOMBIES(ZOMBIE& MALO1, ZOMBIE& MALO2,JUGADOR HEROE);
	
	static bool INTERACCION_BALA_ZOMBIE(DISPARO& BALA, ZOMBIE& MALO);
	static bool INTERACCION_BALA_COLUMNA(DISPARO& BALA, COLUMNA& _COLUMNA);
	static bool INTERACCION_BALA_TABLERO(DISPARO& BALA, TABLERO& _TABLERO);
	static float DISTANCIA_ZOMBIE_HEROE(JUGADOR& HEROE, ZOMBIE& MALO);
};



