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

	
	static void ITERACCION_JUGADOR_TABLERO(JUGADOR& HEROE, TABLERO SUELO);
	static void ITERACCION_JUGADOR_COLUMNA(JUGADOR& HEROE, COLUMNA _COLUMNA);
	static void INTERACCION_JUGADOR_DISPARO(JUGADOR& HEROE, DISPARO& BALA);
	static void INTERACCION_BALA_ZOMBIE(DISPARO& BALA, ZOMBIE& MALO);


	static void INTELIGENCIA_ARTIFICIAL_ZOMBIE(JUGADOR HEROE, ZOMBIE& MALO);

	static void INTERACCION_JUGADOR_TECLADO(JUGADOR& HEROE, unsigned char TECLA);
	


};



