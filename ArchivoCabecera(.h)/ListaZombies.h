#pragma once
#define MAX_ZOMBIES 100
#include "Zombie.h"
#include "Interaccion.h"

class LISTAZOMBIES
{
private:

	ZOMBIE* LISTA[MAX_ZOMBIES]; //Para almacenar objetos de tipo zombie
	int NUMERO; //para llevar la cuenta de los zombies que hay 
	
public:

	LISTAZOMBIES();
	virtual ~LISTAZOMBIES();

	bool AGREGAR(ZOMBIE* z); //Retorna true si no se ha alcanzado el máximo de zombies (MAX_ZOMBIES)
	
	//Funciones dibuja y mueve que acceden a las funciones homónimas para cada objeto zombie de la lista:
	void MUEVE(void);
	void DIBUJA(void);

	void SIGUE_A_JUGADOR(JUGADOR HEROE); //Implementa INTELIGENCIA_ARTIFICIAL_ZOMBIE() para cada zombie de la lista.
	void CHOCA_COLUMNA(COLUMNA COL); //Implementa INTERACCION_ZOMBIE_COLUMNA() para cada zombie de la lista.
	void MATA_DISPARO(DISPARO BALA);
	void CHOQUE_ENTRE_ZOMBIES();
};

