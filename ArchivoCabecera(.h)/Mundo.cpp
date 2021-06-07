#include <Mundo.h>


MUNDO::MUNDO()
{

}

MUNDO::~MUNDO()
{
	ZOMBIES.DESTRUYECONTENIDO();
	BALAS.DESTRUIRDISPAROS();
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

		SUELO.XMAX = 60.0;
		SUELO.ZMAX = 60.0;

		/*PCOLUMNAS[0].TAMANOCOLUMNA = 4;
		PCOLUMNAS[0].POSICION.X = 20.0;
		PCOLUMNAS[0].POSICION.Z = 10.0;

		PCOLUMNAS[1].TAMANOCOLUMNA = 4;
		PCOLUMNAS[1].POSICION.X = 20.0;
		PCOLUMNAS[1].POSICION.Z = 30.0;*/


		for (int i = 0; i < 5; i++)
		{
			ZOMBIE* AUX = new ZOMBIE(15.0f + i * 2, 15.0f + i * 3, 0.05f);

			//PROBLEMA: no sale la implementación del constructor nuevo de los guiones del lab

			//Posiciones XYZ donde aparecen los zombies:
			/*AUX->POSICION.X = 15.0f + i*2;
			AUX->POSICION.Y = 0.0f;
			AUX->POSICION.Z = 15.0f + i*3;

			//Velocidad a la que se mueven (Prueba):
			AUX->VELOCIDAD = 0.05f;*/

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
	BALAS.DIBUJA();
	
	//Habrá que implementar LISTACOLUMNAS
	/*for (int i = 0; i < CO; i++)
	{
		PCOLUMNAS[i].DIBUJA();
	}*/
}

void MUNDO::TECLADO(unsigned char TECLA)
{
	
	if (TECLA == 'w')
	{
		HEROE.setvel(0.0, -5.0);
		direccion_bala = 'w';

	}

	else if (TECLA == 's')
	{
		HEROE.setvel(0.0, 5.0);
		direccion_bala = 's';
	}

	else if (TECLA== 'a')
	{
		HEROE.setvel(-5.0, 0.0);
		direccion_bala = 'a';
	}

	else if (TECLA == 'd')
	{
		HEROE.setvel(5.0, 0.0);
		direccion_bala = 'd';
	}
	if( TECLA == ' ')
	{
		if (direccion_bala == 'w')
		{
			DISPARO* d = new DISPARO(HEROE.POSICION.X, HEROE.POSICION.Z, 0.0, -10.0f);
			BALAS.AGREGAR(d);
		}
		else if (direccion_bala == 's')
		{
			DISPARO* d = new DISPARO(HEROE.POSICION.X, HEROE.POSICION.Z, 0.0, 10.0f);
			BALAS.AGREGAR(d);
		}
		else if (direccion_bala == 'a')
		{
			DISPARO* d = new DISPARO(HEROE.POSICION.X, HEROE.POSICION.Z, -10.0, 0.0);
			BALAS.AGREGAR(d);
		}
		else if (direccion_bala == 'd')
		{
			DISPARO* d = new DISPARO(HEROE.POSICION.X, HEROE.POSICION.Z, 10.0, 0.0);
			BALAS.AGREGAR(d);
		}	
		HEROE.setvel(0.0, 0.0);
	}
	else
	{
		NULL;
	}

}

void MUNDO::MUEVE(float t)
{
	//COLUMNAS.CHOQUE_DISPARO(BALA); //No funciona
	COLUMNAS.CHOQUE_JUGADOR(HEROE); //No funciona
	//COLUMNAS.CHOQUE_ZOMBIE(MALO); //No funciona
	ZOMBIES.MUEVE();
	ZOMBIES.SIGUE_A_JUGADOR(HEROE);
	//ZOMBIES.MATA_DISPARO(BALA);
	ZOMBIES.CHOQUE_ENTRE_ZOMBIES();
	ZOMBIES.COLISION(HEROE);


	HEROE.Mueve(t);


	BALAS.MUEVE(t);
	DISPARO* auxp = BALAS.COLISION_MAPA(SUELO);
	if (auxp != 0)
		BALAS.ELIMINAR(auxp);

	////////////////////////////
	//AQUI SOBRECARGAAAA///////
	//////////////////////////

	/*for (int i = 0; i < BALAS.getNumero(); i++)
	{
		for (int u = 0; u < ZOMBIES.getNumero(); u++)
		{
			if (INTERACCIONES::INTERACCION_BALA_ZOMBIE(*BALAS[i], *ZOMBIES[u]))
			{
				
				ZOMBIES.ELIMINAR(ZOMBIES[u]);
				BALAS.ELIMINAR(BALAS[i]);
				//ETSIDI::play("sonidos/impacto.wav");
				break;
			}
		}
	}*/

	//for (int i = 0; i < CO; i++)
	//{
	//	INTERACCIONES::INTERACCION_BALA_COLUMNA(BALA, PCOLUMNAS[i]);
	//	INTERACCIONES::INTERACCION_JUGADOR_COLUMNA(HEROE, PCOLUMNAS[i]);
	//	ZOMBIES.CHOCA_COLUMNA(PCOLUMNAS[i]);
	//}
}
