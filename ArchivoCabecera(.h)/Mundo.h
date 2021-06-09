#pragma once
#include <Interaccion.h>
#include <ListaZombies.h>
#include <ListaColumnas.h>
#include <ListaDisparos.h>
#include <Jugador.h>
#include <Tablero.h>

class MUNDO
{

private:

	int NUMERODECOLUMNAS;
	bool IMPACTO;
	int NIVEL;
	char direccion_bala;

	JUGADOR HEROE; 
	TABLERO SUELO;
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
	bool CARGARNIVEL(); //Función que gestiona los niveles del juego (FACIL, MEDIO Y DIFICIL)
};

