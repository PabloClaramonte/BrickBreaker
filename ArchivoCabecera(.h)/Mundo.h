#pragma once
#include <Interaccion.h>
#include <ListaZombies.h>
#include <ListaColumnas.h>
#include <ListaDisparos.h>
//#include <Disparo.h>
#include <Jugador.h>
#include <Tablero.h>

//#define CO 2 //Numero de columnas

class MUNDO
{

private:

	int NUMERODECOLUMNAS;
	bool IMPACTO;

	char direccion_bala;

	JUGADOR HEROE;
	//COLUMNA PCOLUMNAS[CO]; 
	TABLERO SUELO;
	//DISPARO BALA;
	LISTAZOMBIES ZOMBIES;
	LISTACOLUMNAS COLUMNAS;
	LISTADISPAROS BALAS;

public:
	MUNDO();
	~MUNDO();

	void CAMARA(void); //para que la camara siga al personaje
	void INICIALIZA();
	void MAPAFACIL(void); //Esta funcion hay que cambiarla por un CargarNivel() como el del pang
	void DIBUJA(void);
	void TECLADO(unsigned char TECLA);
	void MUEVE(float t);
};

