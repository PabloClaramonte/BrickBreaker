#include <Mundo.h>


MUNDO::MUNDO()
{
	
}

MUNDO::~MUNDO()
{
	ZOMBIES.DESTRUYECONTENIDO();
}


void MUNDO::CAMARA(void)
{
	gluLookAt(HEROE.POSICION.X, 40.0f, HEROE.POSICION.Z + 40.0f, // Posicion de la camara.
		HEROE.POSICION.X, 0, HEROE.POSICION.Z, // Punto hacia el que mira la camara.
		0, 1, 0);
}

void MUNDO::INICIALIZA()
{
	MAPAFACIL();
	NUMERODECOLUMNAS = 0;
}


void MUNDO::MAPAFACIL(void)
{
	// Hay que implementar Constructores con argumentos para los objetos

		//JUGADOR* HEROE = new JUGADOR(10.0f, 0.0f, 10.0f, 0.25f); //NO FUNCIONA (?)
		HEROE.POSICION.X = 10.0;
		HEROE.POSICION.Y = 0.0;
		HEROE.POSICION.Z = 10.0;
		HEROE.VELOCIDAD = 0.25;

		SUELO.XMAX = 60.0;
		SUELO.ZMAX = 60.0;

		/*PCOLUMNAS[0].TAMANOCOLUMNA = 4;
		PCOLUMNAS[0].POSICION.X = 20.0;
		PCOLUMNAS[0].POSICION.Z = 10.0;

		PCOLUMNAS[1].TAMANOCOLUMNA = 4;
		PCOLUMNAS[1].POSICION.X = 20.0;
		PCOLUMNAS[1].POSICION.Z = 30.0;*/

		BALA.POSICION.X = 10.0f;
		BALA.POSICION.Y = 0.0f;
		BALA.POSICION.Z = 10.0f;
		BALA.VELOCIDAD = 2.5f;


		for (int i = 0; i < 5; i++)
		{
			ZOMBIE* AUX = new ZOMBIE;

			//PROBLEMA: no sale la implementación del constructor nuevo de los guiones del lab

			//Posiciones XYZ donde aparecen los zombies:
			AUX->POSICION.X = 15.0f + i*2;
			AUX->POSICION.Y = 0.0f;
			AUX->POSICION.Z = 15.0f + i*3;

			//Velocidad a la que se mueven (Prueba):
			AUX->VELOCIDAD = 0.05f;

			ZOMBIES.AGREGAR(AUX); // agregar a la lista
			COLUMNAS.CHOQUE_ZOMBIE(*AUX);
		}

		for (int i = 0; i < 6; i++)
		{
			COLUMNA* AUX = new COLUMNA;

			

			//Posiciones XYZ donde aparecen las columnas:
			AUX->POSICION.X = 15.0f + i * 5;
			AUX->POSICION.Y = 0.0f;
			AUX->POSICION.Z = 5.0f + i * 5;

			COLUMNAS.AGREGAR(AUX); // agregar a la lista
			ZOMBIES.CHOCA_COLUMNA(*AUX); 
		}
}

void MUNDO::DIBUJA(void)
{
	ZOMBIES.DIBUJA();
	COLUMNAS.DIBUJA();
	HEROE.DIBUJA();
	SUELO.DIBUJA();
	BALA.DIBUJA();
	
	//Habrá que implementar LISTACOLUMNAS
	/*for (int i = 0; i < CO; i++)
	{
		PCOLUMNAS[i].DIBUJA();
	}*/
}

void MUNDO::TECLADO(unsigned char TECLA)
{
	INTERACCIONES::INTERACCION_JUGADOR_TECLADO(HEROE, TECLA);
}

void MUNDO::MUEVE(void)
{
	HEROE.MUEVE();
	COLUMNAS.CHOQUE_DISPARO(BALA); //No funciona
	COLUMNAS.CHOQUE_JUGADOR(HEROE); //No funciona
	//COLUMNAS.CHOQUE_ZOMBIE(MALO); //No funciona
	ZOMBIES.MUEVE();
	ZOMBIES.SIGUE_A_JUGADOR(HEROE);
	ZOMBIES.MATA_DISPARO(BALA);
	ZOMBIES.CHOQUE_ENTRE_ZOMBIES();
	ZOMBIES.COLISION(HEROE);
	
	INTERACCIONES::INTERACCION_JUGADOR_TABLERO(HEROE, SUELO);
	INTERACCIONES::INTERACCION_JUGADOR_DISPARO(HEROE, BALA);
	INTERACCIONES::INTERACCION_BALA_TABLERO(BALA, SUELO);

	//for (int i = 0; i < CO; i++)
	//{
	//	INTERACCIONES::INTERACCION_BALA_COLUMNA(BALA, PCOLUMNAS[i]);
	//	INTERACCIONES::INTERACCION_JUGADOR_COLUMNA(HEROE, PCOLUMNAS[i]);
	//	ZOMBIES.CHOCA_COLUMNA(PCOLUMNAS[i]);
	//}
}
