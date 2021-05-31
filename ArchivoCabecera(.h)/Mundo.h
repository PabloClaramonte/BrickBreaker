#pragma once
#include <Interaccion.h>
#include <ListaZombies.h>

#define CO 2 //Numero de columnas

class MUNDO
{

private:

	int NUMERODECOLUMNAS;
	bool IMPACTO;

	JUGADOR HEROE;
	COLUMNA PCOLUMNAS[CO]; //Hacemos LISTACOLUMNAS?? 
	TABLERO SUELO;
	DISPARO BALA;
	LISTAZOMBIES ZOMBIES;

public:
	MUNDO();
	~MUNDO();

	void CAMARA(void); //para que la camara siga al personaje
	void INICIALIZA();
	void MAPAFACIL(void); //Esta funcion hay que cambiarla por un CargarNivel() como el del pang
	void DIBUJA(void);
	void TECLADO(unsigned char TECLA);
	void MUEVE(void);
};

