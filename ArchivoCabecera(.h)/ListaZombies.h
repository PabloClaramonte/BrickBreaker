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

	//Función que gestiona el destructor de cada objeto zombie:
	void DESTRUYECONTENIDO();
	void ELIMINAR(int INDEX); //Elimina zombie según su índice.
	void ELIMINAR(ZOMBIE* z); //Elimina zombie según su dirección de memoria.

	//Funciones que gestionan las interacciones de los zombies con los objetos del juego:
	void SIGUE_A_JUGADOR(JUGADOR HEROE); //Implementa INTELIGENCIA_ARTIFICIAL_ZOMBIE() para cada zombie de la lista.
	void CHOQUE_ENTRE_ZOMBIES(); //Implementa CHOQUE_ENTRE_ZOMBIES() para cada zombie de la lista.
	ZOMBIE* COLISION(JUGADOR HEROE);

	int getNumero();

	ZOMBIE* operator[](int i);

	friend class INTERACCIONES;

};

