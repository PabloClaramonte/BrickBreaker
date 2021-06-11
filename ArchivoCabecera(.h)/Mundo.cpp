#include <Mundo.h>

MUNDO::MUNDO()
{
	IMPACTO = 0;
	NIVEL = 0;
	NUMERODECOLUMNAS = 0;
	direccion_bala = 0;
}

MUNDO::~MUNDO()
{
	ZOMBIES.DESTRUYECONTENIDO();
	COLUMNAS.DESTRUYECONTENIDO();
	BALAS.DESTRUIRDISPAROS();
}


void MUNDO::CAMARA(void)
{
	gluLookAt(HEROE.POSICION.X, 40.0f, (float)HEROE.POSICION.Z + 40.0, // Posicion de la camara.
		HEROE.POSICION.X, 0, HEROE.POSICION.Z, // Punto hacia el que mira la camara.
		0, 1, 0);
}

void MUNDO::INICIALIZA()
{
	IMPACTO = false;
	NIVEL = 0;

	CARGARNIVEL();
}



void MUNDO::DIBUJA(void)
{
	ZOMBIES.DIBUJA();
	COLUMNAS.DIBUJA();
	HEROE.DIBUJA();
	SUELO.DIBUJA();
	BALAS.DIBUJA();
}

void MUNDO::TECLADO(unsigned char TECLA)
{
	
	if (TECLA == 'w')
	{
		HEROE.setvel(0.0, -5.0);
		HEROE.WSAD = 'w';
		direccion_bala = 'w';

	}

	else if (TECLA == 's')
	{
		HEROE.setvel(0.0, 5.0);
		HEROE.WSAD = 's';
		direccion_bala = 's';
	}

	else if (TECLA== 'a')
	{
		HEROE.setvel(-5.0, 0.0);
		HEROE.WSAD = 'a';
		direccion_bala = 'a';
	}

	else if (TECLA == 'd')
	{
		HEROE.setvel(5.0, 0.0);
		HEROE.WSAD = 'd';
		direccion_bala = 'd';
	}
	if( TECLA == ' ')
	{
		if (direccion_bala == 'w')
		{
			DISPARO* d = new DISPARO(HEROE.POSICION.X, HEROE.POSICION.Z, 0.0, -40.0f);
			BALAS.AGREGAR(d);
		}
		else if (direccion_bala == 's')
		{
			DISPARO* d = new DISPARO(HEROE.POSICION.X, HEROE.POSICION.Z, 0.0, 40.0f);
			BALAS.AGREGAR(d);
		}
		else if (direccion_bala == 'a')
		{
			DISPARO* d = new DISPARO(HEROE.POSICION.X, HEROE.POSICION.Z, -40.0, 0.0);
			BALAS.AGREGAR(d);
		}
		else if (direccion_bala == 'd')
		{
			DISPARO* d = new DISPARO(HEROE.POSICION.X, HEROE.POSICION.Z, 40.0, 0.0);
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
	ZOMBIES.MUEVE();
	ZOMBIES.SIGUE_A_JUGADOR(HEROE);
	ZOMBIES.CHOQUE_ENTRE_ZOMBIES();
	BALAS.MUEVE(t);
	INTERACCIONES::INTERACCION_JUGADOR_TABLERO(HEROE, SUELO);

	//Interacción columnas con personaje:
	COLUMNAS.CHOQUE_JUGADOR(HEROE);
	if (COLUMNAS.CHOQUE_JUGADOR(HEROE))
	{
		ETSIDI::play("sonidos/impacto.wav");	
	}
	else
	{
		HEROE.MUEVE(t);
	}

	//Interacción zombies con el jugador
	ZOMBIE* AUXZ = ZOMBIES.COLISION(HEROE);
	if (AUXZ != 0) {
		IMPACTO = true;
		ETSIDI::play("sonidos/impacto.wav");
	}
	
	//Interaccción de las balas con el final del mapa
	DISPARO* auxp = BALAS.COLISION_MAPA(SUELO);
	if (auxp != 0)
		BALAS.ELIMINAR(auxp);


	for (int i = 0; i < BALAS.getNumero(); i++)
	{
		for (int u = 0; u < ZOMBIES.getNumero(); u++)
		{
			if (INTERACCIONES::INTERACCION_BALA_ZOMBIE(*BALAS[i], *ZOMBIES[u]))
			{
				ZOMBIES.ELIMINAR(ZOMBIES[u]);
				BALAS.ELIMINAR(BALAS[i]);
				ETSIDI::play("sonidos/impacto.wav");
				break;
			}
		}
	}

	//INTERACCIÓN BALAS CON LAS COLUMNAS
	for (int i = 0; i < BALAS.getNumero(); i++)
	{
		for (int u = 0; u < COLUMNAS.getNumero(); u++)
		{
			if (INTERACCIONES::INTERACCION_BALA_COLUMNA(*BALAS[i], *COLUMNAS[u]))
			{
				BALAS.ELIMINAR(BALAS[i]);
				//SIDI::play("sonidos/impacto.wav");
				break;
			}
		}
	}

	//INTERACCION ZOMBIES CON COLUMNAS
	for (int i = 0; i < ZOMBIES.getNumero(); i++)
	{
		for (int u = 0; u < COLUMNAS.getNumero(); u++)
		{
			INTERACCIONES::INTERACCION_ZOMBIE_COLUMNA(*ZOMBIES[i], *COLUMNAS[u]);
		}
	}
}


bool MUNDO::CARGARNIVEL()
{
	NIVEL++;
	HEROE.POSICION.X = 0.0f;
	HEROE.POSICION.Z = 0.0f;
	ZOMBIES.DESTRUYECONTENIDO();
	COLUMNAS.DESTRUYECONTENIDO();
	BALAS.DESTRUIRDISPAROS();

	if (NIVEL == 1)
	{
		MAPAFACIL();
	}
	if (NIVEL == 2)
	{
		MAPAMEDIO();
	}
	if (NIVEL == 3)
	{
		MAPADIFICIL();
	}

	if (NIVEL <= 3)
		return true;
	return false;
}

int MUNDO::GETZOMBIES()
{
	int N;
	N = ZOMBIES.getNumero();
	return N;
}

bool MUNDO::GETIMPACTO()
{
	bool i;
	i = IMPACTO;
	return i;
}

void MUNDO::MAPAFACIL(void)
{
	//JUGADOR* HEROE = new JUGADOR(10.0f, 0.0f, 10.0f, 0.25f); //NO FUNCIONA (?)
	HEROE.POSICION.X = 10.0;
	HEROE.POSICION.Z = 10.0;

	//TABLERO* SUELO = new TABLERO(60.0f, 60.0f); //NO FUNCIONA (?)
	SUELO.XMAX = 60.0;
	SUELO.ZMAX = 60.0;

	for (int i = 0; i < 5; i++)
	{
		ZOMBIE* AUX = new ZOMBIE(15.0f + i * 5, 20.0f + i * 5, (float)((rand() % 3) + 1) * 0.01);
		ZOMBIES.AGREGAR(AUX);
	}


		COLUMNA* AUX1 = new COLUMNA(15.0f, 15.0f, 4); //COnstruye e inicializa los objetos columna

		COLUMNAS.AGREGAR(AUX1); // agregar a la lista

		COLUMNA* AUX2 = new COLUMNA(45.0f, 15.0f, 4); //COnstruye e inicializa los objetos columna

		COLUMNAS.AGREGAR(AUX2); // agregar a la lista

		COLUMNA* AUX3 = new COLUMNA(15.0f, 45.0f, 4); //COnstruye e inicializa los objetos columna

		COLUMNAS.AGREGAR(AUX3); // agregar a la lista

		COLUMNA* AUX4 = new COLUMNA(45.0f, 45.0f, 4); //COnstruye e inicializa los objetos columna

		COLUMNAS.AGREGAR(AUX4); // agregar a la lista

}

void MUNDO::MAPAMEDIO(void)
{
	//JUGADOR* HEROE = new JUGADOR(10.0f, 0.0f, 10.0f, 0.25f); //NO FUNCIONA (?)
	HEROE.POSICION.X = 10.0;
	HEROE.POSICION.Z = 10.0;

	//TABLERO* SUELO = new TABLERO(60.0f, 60.0f); //NO FUNCIONA (?)
	SUELO.XMAX = 60.0;
	SUELO.ZMAX = 60.0;

	for (int i = 0; i < 5; i++)
	{
		ZOMBIE* AUX = new ZOMBIE(15.0f + i * 2, 15.0f + i * 3, 0.05f); //Construye e inicializa los objetos zombies

		ZOMBIES.AGREGAR(AUX); // agregar a la lista
	}

	for (int i = 0; i < 6; i++)
	{
		COLUMNA* AUX = new COLUMNA(15.0f + i * 7, 5.0f + i * 7, 4); //COnstruye e inicializa los objetos columna

		COLUMNAS.AGREGAR(AUX); // agregar a la lista
	}
}

void MUNDO::MAPADIFICIL(void)
{
	//JUGADOR* HEROE = new JUGADOR(10.0f, 0.0f, 10.0f, 0.25f); //NO FUNCIONA (?)
	HEROE.POSICION.X = 10.0;
	HEROE.POSICION.Z = 10.0;

	//TABLERO* SUELO = new TABLERO(60.0f, 60.0f); //NO FUNCIONA (?)
	SUELO.XMAX = 60.0;
	SUELO.ZMAX = 60.0;

	for (int i = 0; i < 5; i++)
	{
		ZOMBIE* AUX = new ZOMBIE(15.0f + i * 2, 15.0f + i * 3, 0.05f); //Construye e inicializa los objetos zombies

		ZOMBIES.AGREGAR(AUX); // agregar a la lista
	}

	for (int i = 0; i < 6; i++)
	{
		COLUMNA* AUX = new COLUMNA(15.0f + i * 7, 5.0f + i * 7, 4); //COnstruye e inicializa los objetos columna

		COLUMNAS.AGREGAR(AUX); // agregar a la lista
	}
}