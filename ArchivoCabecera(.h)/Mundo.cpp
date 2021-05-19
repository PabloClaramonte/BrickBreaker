#include <Mundo.h>

MUNDO::MUNDO()
{
	NUMERODECOLUMNAS = 0;
}

MUNDO::~MUNDO()
{
}


void MUNDO::CAMARA(void)
{
	gluLookAt(HEROE.POSICION.X, HEROE.POSICION.Y + 40, HEROE.POSICION.Z + 40, // Posicion de la camara.
		HEROE.POSICION.X, HEROE.POSICION.Y, HEROE.POSICION.Z, // Punto hacia el que mira la camara.
		0, 1, 0);
}


void MUNDO::MAPAFACIL(void)
{
	// Hay que implementar otro Constructor para heroe HEROE(X,Y,Z,VEL);
		HEROE.POSICION.X = 10.0;
		HEROE.POSICION.Y = 0.0;
		HEROE.POSICION.Z = 10.0;
		HEROE.VELOCIDAD = 0.25;

		SUELO.XMAX = 40.0;
		SUELO.ZMAX = 40.0;

		PCOLUMNAS[0].TAMANOCOLUMNA = 4;
		PCOLUMNAS[0].POSICION.X = 20.0;
		PCOLUMNAS[0].POSICION.Z = 10.0;

		PCOLUMNAS[1].TAMANOCOLUMNA = 4;
		PCOLUMNAS[1].POSICION.X = 20.0;
		PCOLUMNAS[1].POSICION.Z = 30.0;

		BALA.POSICION.X = 10.0;
		BALA.POSICION.Y = 0.0;
		BALA.POSICION.Z = 10.0;
		BALA.VELOCIDAD = 2.5;


		for (int i = 0; i < 15; i++)
		{
			ZOMBIE* AUX = new ZOMBIE;

			//PROBLEMA: no sale la implementación del constructor nuevo de los guiones del lab

			//Posiciones XYZ donde aparecen los zombies:
			AUX->POSICION.X = 15.0f + i*2;
			AUX->POSICION.Y = 0.0f;
			AUX->POSICION.Z = 15.0f + i*3;

			//Velocidad a la que se mueven (Prueba):
			AUX->VELOCIDAD = 0.05f + 0.005 * i;

			ZOMBIES.AGREGAR(AUX); // agregar a la lista
		}
}

void MUNDO::DIBUJA(void)
{
	ZOMBIES.DIBUJA();
	HEROE.DIBUJA();
	SUELO.DIBUJA();
	BALA.DIBUJA();
	
	//Habrá que implementar LISTACOLUMNAS
	for (int i = 0; i < CO; i++)
	{
		PCOLUMNAS[i].DIBUJAR();
	}
}

void MUNDO::TECLADO(unsigned char TECLA)
{
	INTERACCIONES::INTERACCION_JUGADOR_TECLADO(HEROE, TECLA);
}

void MUNDO::MUEVE(void)
{
	HEROE.MUEVE();
	ZOMBIES.MUEVE();
	ZOMBIES.SIGUE_A_JUGADOR(HEROE);
	ZOMBIES.MATA_DISPARO(BALA);
	ZOMBIES.CHOQUE_ENTRE_ZOMBIES();


	INTERACCIONES::INTERACCION_JUGADOR_TABLERO(HEROE, SUELO);
	INTERACCIONES::INTERACCION_JUGADOR_DISPARO(HEROE, BALA);

	for (int i = 0; i < CO; i++)
	{
		INTERACCIONES::INTERACCION_JUGADOR_COLUMNA(HEROE, PCOLUMNAS[i]);
		ZOMBIES.CHOCA_COLUMNA(PCOLUMNAS[i]);
	}
	
}
