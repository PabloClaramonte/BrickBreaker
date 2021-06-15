#pragma once

#include <math.h>

#include <Jugador.h>
#include <Tablero.h>
#include <Columna.h>
#include <Disparo.h>
#include <Zombie.h>
#include <Bonus.h>

class INTERACCIONES
{
public:
	//Funciones static porque es una función que queremos utilizar independientemente de que haya o no un objeto

	//INTERACCIONES JUGADOR
	static bool COLISION(JUGADOR& HEROE, COLUMNA& _COLUMNA);
	static bool COLISION(JUGADOR& HEROE, ZOMBIE& MALO);
	static void COLISION(JUGADOR& HEROE, TABLERO& SUELO);
	static bool COLISION(JUGADOR HEROE, BONUS& REWARD);
	//INTERACCION ZOMBIE
	static void COLISION(ZOMBIE& MALO, COLUMNA& _COLUMNA);
	static void INTELIGENCIA_ARTIFICIAL_ZOMBIE(JUGADOR& HEROE, ZOMBIE& MALO);
	static void COLISION(ZOMBIE& MALO1, ZOMBIE& MALO2,JUGADOR HEROE);
	static float DISTANCIA_ZOMBIE_HEROE(JUGADOR& HEROE, ZOMBIE& MALO);
	//INTERACCION DISPARO
	static bool COLISION(DISPARO& BALA, ZOMBIE& MALO);
	static bool COLISION(DISPARO& BALA, COLUMNA& _COLUMNA);
	static bool COLISION(DISPARO& BALA, TABLERO& _TABLERO);
	
	

};



