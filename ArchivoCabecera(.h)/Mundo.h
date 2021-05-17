#pragma once
#include <Interaccion.h>

#define ZO 2 //Numero de zombis
#define CO 2 //Numero de columnas

class MUNDO
{

private:

	int NUMERODECOLUMNAS;

	JUGADOR HEROE;
	COLUMNA PCOLUMNAS[CO];
	TABLERO SUELO;
	DISPARO BALA;
	ZOMBIE MALO[ZO];

public:
	MUNDO();
	~MUNDO();

	void CAMARA(void); //para que la camara siga al personaje
	void MAPAFACIL(void);
	void DIBUJA(void);
	void TECLADO(unsigned char TECLA);
	void MUEVE(void);
};

