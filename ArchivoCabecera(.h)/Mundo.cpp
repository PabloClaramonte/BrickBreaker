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
		BALA.VELOCIDAD = 2;

		MALO[0].POSICION.X = 25.0;
		MALO[0].POSICION.Y = 0.0;
		MALO[0].POSICION.Z = 30.0;
		MALO[0].VELOCIDAD = 0.15;
		MALO[0].VIVO = true;

		MALO[1].POSICION.X = 35.0;
		MALO[1].POSICION.Y = 0.0;
		MALO[1].POSICION.Z = 10.0;
		MALO[1].VELOCIDAD = 0.15;
		MALO[1].VIVO = true;
}

void MUNDO::DIBUJA(void)
{
	HEROE.DIBUJA();
	SUELO.DIBUJA();
	BALA.DIBUJA();

	for (int i = 0; i < CO; i++)
	{
		PCOLUMNAS[i].DIBUJAR();
	}
	for (int i = 0; i < ZO; i++)
	{
		MALO[i].DIBUJA();
	}
}

void MUNDO::TECLADO(unsigned char TECLA)
{
	INTERACCIONES::INTERACCION_JUGADOR_TECLADO(HEROE, TECLA);
}

void MUNDO::MUEVE(void)
{
	HEROE.MUEVE();

	INTERACCIONES::INTERACCION_JUGADOR_TABLERO(HEROE, SUELO);
	INTERACCIONES::INTERACCION_JUGADOR_DISPARO(HEROE, BALA);

	for (int i = 0; i < CO; i++)
	{
		INTERACCIONES::INTERACCION_JUGADOR_COLUMNA(HEROE, PCOLUMNAS[i]);
	}
	for (int i = 0; i < ZO; i++)
	{
		MALO[i].MUEVE();
		INTERACCIONES::INTERACCION_BALA_ZOMBIE(BALA, MALO[i]);
		INTERACCIONES::INTELIGENCIA_ARTIFICIAL_ZOMBIE(HEROE, MALO[i]);
	}
}
