#include <Mundo.h>
#include "stdlib.h"

MUNDO::MUNDO()
{
	IMPACTO = 0;
	NIVEL = 0;
	NUMERODECOLUMNAS = 0;
	direccion_bala = 0;
	modo_escopeta = false;
	num_disp_escp = 0;
}

MUNDO::~MUNDO()
{
	ZOMBIES.DESTRUYECONTENIDO();
	COLUMNAS.DESTRUYECONTENIDO();
	BALAS.DESTRUIRDISPAROS();
	_BONUS.DESTRUIRBONUS();
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
	_BONUS.DIBUJA();
}

void MUNDO::TECLADO(unsigned char TECLA)
{
	
	if (TECLA == 'w' || TECLA == 'W')
	{
		HEROE.setvel(0.0, -5.0);
		HEROE.WSAD = 'w';
		direccion_bala = 'w';
	}

	else if (TECLA == 's' || TECLA == 'S')
	{
		HEROE.setvel(0.0, 5.0);
		HEROE.WSAD = 's';
		direccion_bala = 's';
	}

	else if (TECLA== 'a' || TECLA == 'A')
	{
		HEROE.setvel(-5.0, 0.0);
		HEROE.WSAD = 'a';
		direccion_bala = 'a';
	}

	else if (TECLA == 'd' || TECLA == 'D')
	{
		HEROE.setvel(5.0, 0.0);
		HEROE.WSAD = 'd';
		direccion_bala = 'd';
	}
	if( TECLA == ' ')
	{
		ETSIDI::play("sonidos/disparo.wav");
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
	//DISPARO CON ESCOPETA//
	if (TECLA == 'b' || TECLA == 'B' && modo_escopeta==true)
	{
		ETSIDI::play("sonidos/escopeta.wav");
		num_disp_escp--;
		if (direccion_bala == 'w')
		{
			for (int i = -1; i <= 1; i++)
			{
				ESCOPETA* es = new ESCOPETA(HEROE.POSICION.X, HEROE.POSICION.Z, 10.0 * i, -40.0f, 1.0f, 0.75f);
				BALAS.AGREGAR(es);
			}
		}
		else if (direccion_bala == 's')
		{
			for (int i = -1; i <= 1; i++)
			{
				ESCOPETA* es = new ESCOPETA(HEROE.POSICION.X, HEROE.POSICION.Z, 10.0 * i, 40.0f, 1.0f, 0.75f);
				BALAS.AGREGAR(es);
			}
		}
		else if (direccion_bala == 'a')
		{
			for (int i = -1; i <= 1; i++)
			{
				ESCOPETA* es = new ESCOPETA(HEROE.POSICION.X, HEROE.POSICION.Z,  -40.0f, 10.0 * i, 1.0f, 0.75f);
				BALAS.AGREGAR(es);
			}
		}
		else if (direccion_bala == 'd')
		{
			for (int i = -1; i <= 1; i++)
			{
				ESCOPETA* es = new ESCOPETA(HEROE.POSICION.X, HEROE.POSICION.Z, 40.0f, 10.0 * i, 1.0f, 0.75f);
				BALAS.AGREGAR(es);
			}
		}
		HEROE.setvel(0.0, 0.0);
		if (num_disp_escp==0)
		{
			modo_escopeta = false;
		}

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
		ETSIDI::play("sonidos/GameOver.wav");
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
				probabilidad = (rand() % 3);
				if (ZOMBIES[u]->getImpacto() == 5)
				{
					if (probabilidad == 1)
					{
						PUNTOSCARTESIANOS pos = ZOMBIES[u]->getPos();
						BONUS* bonus = new BONUS(pos.X, pos.Z);
						_BONUS.AGREGAR(bonus);
					}
					ZOMBIES.ELIMINAR(ZOMBIES[u]);	
				}
				BALAS.ELIMINAR(BALAS[i]);
				ETSIDI::play("sonidos/zombieMuerte.wav");
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
				ETSIDI::play("sonidos/impacto.wav");
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

	BONUS* AUX = _BONUS.COLISION(HEROE);
	if (AUX != 0) 
	{
		modo_escopeta = true;
		num_disp_escp+=5;
		_BONUS.ELIMINAR(AUX);
		ETSIDI::play("sonidos/recarga.wav");
	}
}


bool MUNDO::CARGARNIVEL()
{
	NIVEL++;
	ZOMBIES.DESTRUYECONTENIDO();
	COLUMNAS.DESTRUYECONTENIDO();
	BALAS.DESTRUIRDISPAROS();
	//_BONUS.DESTRUIRBONUS();

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
	HEROE.POSICION.X = 30.0;
	HEROE.POSICION.Z = 30.0;

	SUELO.XMAX = 60.0;
	SUELO.ZMAX = 60.0;

	_BONUS.DESTRUIRBONUS();

	COLUMNA* AUX1 = new COLUMNA(15.0f, 15.0f, 4); //COnstruye e inicializa los objetos columna

	COLUMNAS.AGREGAR(AUX1); // agregar a la lista

	COLUMNA* AUX2 = new COLUMNA(45.0f, 15.0f, 4); //COnstruye e inicializa los objetos columna

	COLUMNAS.AGREGAR(AUX2); // agregar a la lista

	COLUMNA* AUX3 = new COLUMNA(15.0f, 45.0f, 4); //COnstruye e inicializa los objetos columna

	COLUMNAS.AGREGAR(AUX3); // agregar a la lista

	COLUMNA* AUX4 = new COLUMNA(45.0f, 45.0f, 4); //COnstruye e inicializa los objetos columna

	COLUMNAS.AGREGAR(AUX4); // agregar a la lista


	for (int i = 0; i < 2; i++)
	{
		ZOMBIE* AUX = new ZOMBIE(2.0, 0.0f + (i * 30), 0.0f, (float)((rand() % 4) + 1) * 0.01, 4);
		ZOMBIES.AGREGAR(AUX);
	}

	for (int i = 0; i < 2; i++)
	{
		ZOMBIE* AUX = new ZOMBIE(2.0, 30.0f + (i * 30), 60.0f, (float)((rand() % 4) + 1) * 0.01, 4);
		ZOMBIES.AGREGAR(AUX);
	}

	for (int i = 0; i < 2; i++)
	{
		ZOMBIE* AUX = new ZOMBIE(2.0, 0.0f, 30.0f + (i * 30), (float)((rand() % 4) + 1) * 0.01, 4);
		ZOMBIES.AGREGAR(AUX);
	}
	for (int i = 0; i < 2; i++)
	{
		ZOMBIE* AUX = new ZOMBIE(2.0, 60.0f, 0.0f + (i * 30), (float)((rand() % 4) + 1) * 0.01, 4);
		ZOMBIES.AGREGAR(AUX);
	}




}

void MUNDO::MAPAMEDIO(void)
{
	COLUMNA* AUX1 = new COLUMNA(15.0f, 15.0f, 4); //COnstruye e inicializa los objetos columna

	COLUMNAS.AGREGAR(AUX1); // agregar a la lista

	COLUMNA* AUX2 = new COLUMNA(45.0f, 15.0f, 4); //COnstruye e inicializa los objetos columna

	COLUMNAS.AGREGAR(AUX2); // agregar a la lista

	COLUMNA* AUX3 = new COLUMNA(15.0f, 45.0f, 4); //COnstruye e inicializa los objetos columna

	COLUMNAS.AGREGAR(AUX3); // agregar a la lista

	COLUMNA* AUX4 = new COLUMNA(45.0f, 45.0f, 4); //COnstruye e inicializa los objetos columna

	COLUMNAS.AGREGAR(AUX4); // agregar a la lista



	for (int i = 0; i < 4; i++)
	{
		ZOMBIE* AUX = new ZOMBIE(2.0, 0.0f + (i * 15), 0.0f, (float)((rand() % 4) + 1) * 0.01, 4);
		ZOMBIES.AGREGAR(AUX);
	}

	for (int i = 0; i < 2; i++)
	{
		ZOMBIE* AUX = new ZOMBIE(2.0, 30.0f + (i * 30), 60.0f, (float)((rand() % 4) + 1) * 0.01, 4);
		ZOMBIES.AGREGAR(AUX);
	}

	for (int i = 0; i < 2; i++)
	{
		ZOMBIE* AUX = new ZOMBIE(2.0, 0.0f, 30.0f + (i * 30), (float)((rand() % 4) + 1) * 0.01, 4);
		ZOMBIES.AGREGAR(AUX);
	}
	for (int i = 0; i < 4; i++)
	{
		ZOMBIE* AUX = new ZOMBIE(2.0, 60.0f, 0.0f + (i * 15), (float)((rand() % 4) + 1) * 0.01, 4);
		ZOMBIES.AGREGAR(AUX);
	}


	SUPERZOMBIE* sz1 = new SUPERZOMBIE(2.5f, 0.0f, 0.0f, 0.05f, 0);
	ZOMBIES.AGREGAR(sz1);

	SUPERZOMBIE* sz2 = new SUPERZOMBIE(2.5f, 60.0f, 0.0f, 0.05f, 0);
	ZOMBIES.AGREGAR(sz2);




}

void MUNDO::MAPADIFICIL(void)
{

	COLUMNA* AUX1 = new COLUMNA(15.0f, 15.0f, 4); //COnstruye e inicializa los objetos columna

	COLUMNAS.AGREGAR(AUX1); // agregar a la lista

	COLUMNA* AUX2 = new COLUMNA(45.0f, 15.0f, 4); //COnstruye e inicializa los objetos columna

	COLUMNAS.AGREGAR(AUX2); // agregar a la lista

	COLUMNA* AUX3 = new COLUMNA(15.0f, 45.0f, 4); //COnstruye e inicializa los objetos columna

	COLUMNAS.AGREGAR(AUX3); // agregar a la lista

	COLUMNA* AUX4 = new COLUMNA(45.0f, 45.0f, 4); //COnstruye e inicializa los objetos columna



	COLUMNAS.AGREGAR(AUX4); // agregar a la lista
	for (int i = 0; i < 3; i++)
	{
		ZOMBIE* AUX = new ZOMBIE(2.0, 12.0f + (i * 12), 0.0f, (float)((rand() % 4) + 1) * 0.01, 4);
		ZOMBIES.AGREGAR(AUX);
	}

	for (int i = 0; i < 3; i++)
	{
		ZOMBIE* AUX = new ZOMBIE(2.0, 0.0f, 12.0f + (i * 12), (float)((rand() % 4) + 1) * 0.01, 4);
		ZOMBIES.AGREGAR(AUX);
	}

	for (int i = 0; i < 3; i++)
	{
		ZOMBIE* AUX = new ZOMBIE(2.0, 60.0f, 12.0f + (i * 12), (float)((rand() % 4) + 1) * 0.01, 4);
		ZOMBIES.AGREGAR(AUX);
	}

	for (int i = 0; i < 3; i++)
	{
		ZOMBIE* AUX = new ZOMBIE(2.0, 12.0f + (i * 12), 60.0f, (float)((rand() % 4) + 1) * 0.01, 4);
		ZOMBIES.AGREGAR(AUX);
	}


	SUPERZOMBIE* sz1 = new SUPERZOMBIE (2.5f, 0.0f, 0.0f, 0.05f, 0);
	ZOMBIES.AGREGAR(sz1);

	SUPERZOMBIE* sz2 = new SUPERZOMBIE(2.5f, 60.0f, 0.0f, 0.05f, 0);
	ZOMBIES.AGREGAR(sz2);

	SUPERZOMBIE* sz3 = new SUPERZOMBIE(2.5f, 60.0f, 60.0f, 0.05f, 0);
	ZOMBIES.AGREGAR(sz3);

	SUPERZOMBIE* sz4 = new SUPERZOMBIE(2.5f, 0.0f, 60.0f, 0.05f,0);
	ZOMBIES.AGREGAR(sz4);



}