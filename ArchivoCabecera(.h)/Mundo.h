#pragma once
#include <Interaccion.h>
#include <ListaZombies.h>
#include <ListaColumnas.h>
#include <ListaDisparos.h>
#include <Jugador.h>
#include <Tablero.h>
#include <escopeta.h>
#include <SuperZombie.h>
#include <Bonus.h>

class MUNDO
{

private:

	int NUMERODECOLUMNAS;
	bool IMPACTO;
	int NIVEL;
	char direccion_bala;
	int probabilidad;


	JUGADOR HEROE; 
	TABLERO SUELO;
	LISTAZOMBIES ZOMBIES;
	LISTACOLUMNAS COLUMNAS;
	LISTADISPAROS BALAS;
	BONUS _BONUS;

public:
	MUNDO();
	~MUNDO();

	void CAMARA(void); //para que la camara siga al personaje
	void INICIALIZA();
	void MAPAFACIL(void); //Esta funcion hay que cambiarla por un CargarNivel() como el del pang
	void MAPAMEDIO(void);
	void MAPADIFICIL(void);
	void DIBUJA(void);
	void TECLADO(unsigned char TECLA);
	void MUEVE(float t);
	bool CARGARNIVEL(); //Función que gestiona los niveles del juego (FACIL, MEDIO Y DIFICIL)
	int GETZOMBIES(); //Obtiene el número de zombies vivos que hay en el mapa 
	bool GETIMPACTO();
};

