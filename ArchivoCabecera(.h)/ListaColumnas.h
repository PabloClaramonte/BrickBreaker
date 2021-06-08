#pragma once

#define MAX_COLUMNAS 10
#include "Columna.h"
#include "Interaccion.h"

class LISTACOLUMNAS
{
private:
	COLUMNA* LISTA[MAX_COLUMNAS]; //Para almacenar objetos de tipo columna
	int NUMERO; //para llevar la cuenta de las columnas que hay 

public:

	LISTACOLUMNAS();
	virtual ~LISTACOLUMNAS();

	bool AGREGAR(COLUMNA* c); //Retorna true si no se ha alcanzado el m�ximo de columnas (MAX_COLUMNAS)

	//Funcion dibuja que accede a las funcion hom�nima para cada objeto columna de la lista:
	void DIBUJA(void);

	//Funci�n que gestiona el destructor de cada objeto columna:
	void DESTRUYECONTENIDO();
	void ELIMINAR(int INDEX); //Elimina columna seg�n su �ndice.
	void ELIMINAR(COLUMNA* c); //Elimina columna seg�n su direcci�n de memoria.

	//Funciones que gestionan las interacciones de las columnas con los objetos del juego:
	/*void CHOQUE_JUGADOR(JUGADOR HEROE);
	void CHOQUE_DISPARO(DISPARO BALA);
	void CHOQUE_ZOMBIE(ZOMBIE MALO);*/

	int getNumero();
	COLUMNA* operator [](int i);
};

