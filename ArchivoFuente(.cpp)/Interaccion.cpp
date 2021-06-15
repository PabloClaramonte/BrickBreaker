#include "Interaccion.h"
#include "math.h"

//Función que evita que el jugador atraviese las columnas:

bool INTERACCIONES::COLISION(JUGADOR& HEROE, COLUMNA& _COLUMNA)
{
	if (HEROE.POSICION.X >= _COLUMNA.POSICION.X - (_COLUMNA.TAMANOCOLUMNA / 2) && HEROE.POSICION.X <= _COLUMNA.POSICION.X + (_COLUMNA.TAMANOCOLUMNA / 2) && HEROE.POSICION.Z >= _COLUMNA.POSICION.Z - (_COLUMNA.TAMANOCOLUMNA) && HEROE.POSICION.Z <= _COLUMNA.POSICION.Z - (_COLUMNA.TAMANOCOLUMNA / 2))
	{
		if (HEROE.WSAD == 's')
		{
			HEROE.setvel(0.0, 0.0);
			return true;
		}

		else
		{
			return false;
		}

	}
	else if (HEROE.POSICION.X >= _COLUMNA.POSICION.X - (_COLUMNA.TAMANOCOLUMNA / 2) && HEROE.POSICION.X <= _COLUMNA.POSICION.X + (_COLUMNA.TAMANOCOLUMNA / 2) && HEROE.POSICION.Z >= _COLUMNA.POSICION.Z + (_COLUMNA.TAMANOCOLUMNA / 2) && HEROE.POSICION.Z <= _COLUMNA.POSICION.Z + (_COLUMNA.TAMANOCOLUMNA))
	{
		if (HEROE.WSAD == 'w')
		{
			HEROE.setvel(0.0, 0.0);
			return true;
		}
		else
		{
			return false;
		}

	}
	else if (HEROE.POSICION.Z >= _COLUMNA.POSICION.Z - (_COLUMNA.TAMANOCOLUMNA / 2) && HEROE.POSICION.Z <= _COLUMNA.POSICION.Z + (_COLUMNA.TAMANOCOLUMNA / 2) && HEROE.POSICION.X >= _COLUMNA.POSICION.X - (_COLUMNA.TAMANOCOLUMNA) && HEROE.POSICION.X <= _COLUMNA.POSICION.X + (_COLUMNA.TAMANOCOLUMNA / 2))
	{
		if (HEROE.WSAD == 'd')
		{
			HEROE.setvel(0.0, 0.0);
			return true;
		}
		else
		{
			return false;
		}

	}
	else if (HEROE.POSICION.Z >= _COLUMNA.POSICION.Z - (_COLUMNA.TAMANOCOLUMNA / 2) && HEROE.POSICION.Z <= _COLUMNA.POSICION.Z + (_COLUMNA.TAMANOCOLUMNA / 2) && HEROE.POSICION.X >= _COLUMNA.POSICION.X + (_COLUMNA.TAMANOCOLUMNA / 2) && HEROE.POSICION.X <= _COLUMNA.POSICION.X + (_COLUMNA.TAMANOCOLUMNA))
	{
		if (HEROE.WSAD == 'a')
		{
			HEROE.setvel(0.0, 0.0);
			return true;
		}
		else
		{
			return false;
		}

	}


	else if (HEROE.POSICION.X >= _COLUMNA.POSICION.X - (_COLUMNA.TAMANOCOLUMNA - 0.126) && HEROE.POSICION.X <= _COLUMNA.POSICION.X + ((_COLUMNA.TAMANOCOLUMNA / 2)) && HEROE.POSICION.Z >= _COLUMNA.POSICION.Z - (_COLUMNA.TAMANOCOLUMNA - 0.126) && HEROE.POSICION.Z <= _COLUMNA.POSICION.Z - (_COLUMNA.TAMANOCOLUMNA / 2))
	{
		if (HEROE.WSAD == 's')
		{
			HEROE.setvel(0.0, 0.0);
			return true;
		}
		else if (HEROE.WSAD == 'd')
		{
			HEROE.setvel(0.0, 0.0);
			return true;
		}
		else
		{
			return false;
		}

	}
	else if (HEROE.POSICION.X >= _COLUMNA.POSICION.X + (_COLUMNA.TAMANOCOLUMNA / 2) && HEROE.POSICION.X <= _COLUMNA.POSICION.X + (_COLUMNA.TAMANOCOLUMNA - 0.126) && HEROE.POSICION.Z >= _COLUMNA.POSICION.Z - (_COLUMNA.TAMANOCOLUMNA - 0.126) && HEROE.POSICION.Z <= _COLUMNA.POSICION.Z - (_COLUMNA.TAMANOCOLUMNA / 2))
	{
		if (HEROE.WSAD == 's')
		{
			HEROE.setvel(0.0, 0.0);
			return true;
		}
		else if (HEROE.WSAD == 'a')
		{
			HEROE.setvel(0.0, 0.0);
			return true;
		}
		else
		{
			return false;
		}

	}
	else if ((HEROE.POSICION.X >= _COLUMNA.POSICION.X - (_COLUMNA.TAMANOCOLUMNA - 0.126) && HEROE.POSICION.X <= _COLUMNA.POSICION.X - (_COLUMNA.TAMANOCOLUMNA / 2) && HEROE.POSICION.Z >= _COLUMNA.POSICION.Z + (_COLUMNA.TAMANOCOLUMNA / 2) && HEROE.POSICION.Z <= _COLUMNA.POSICION.Z + (_COLUMNA.TAMANOCOLUMNA - 0.126)))
	{
		if (HEROE.WSAD == 'w')
		{
			HEROE.setvel(0.0, 0.0);
			return true;
		}
		else if (HEROE.WSAD == 'd')
		{
			HEROE.setvel(0.0, 0.0);
			return true;
		}
		else
		{
			return false;
		}

	}
	else if ((HEROE.POSICION.X >= _COLUMNA.POSICION.X + (_COLUMNA.TAMANOCOLUMNA / 2) && HEROE.POSICION.X <= _COLUMNA.POSICION.X + (_COLUMNA.TAMANOCOLUMNA - 0.126) && HEROE.POSICION.Z >= _COLUMNA.POSICION.Z + (_COLUMNA.TAMANOCOLUMNA / 2) && HEROE.POSICION.Z <= _COLUMNA.POSICION.Z + (_COLUMNA.TAMANOCOLUMNA - 0.126)))
	{
		if (HEROE.WSAD == 'w')
		{
			HEROE.setvel(0.0, 0.0);
			return true;
		}
		else if (HEROE.WSAD == 'a')
		{
			HEROE.setvel(0.0, 0.0);
			return true;
		}
		else
		{
			return false;
		}

	}
	else
	{
		return false;
	}
}

//Función que evita que los zombies atraviesen las columnas:

void INTERACCIONES::COLISION(ZOMBIE& MALO, COLUMNA& _COLUMNA)
{
	if (MALO.POSICION.X >= _COLUMNA.POSICION.X - (_COLUMNA.TAMANOCOLUMNA) && MALO.POSICION.X <= _COLUMNA.POSICION.X + (_COLUMNA.TAMANOCOLUMNA) && MALO.POSICION.Z <= _COLUMNA.POSICION.Z - (_COLUMNA.TAMANOCOLUMNA/2) && MALO.POSICION.Z >= _COLUMNA.POSICION.Z - (_COLUMNA.TAMANOCOLUMNA+0.075))
	{
		if (sinf(MALO.ANGULO)>=0)
		{
			MALO.POSICION.Z = _COLUMNA.POSICION.Z - _COLUMNA.TAMANOCOLUMNA;
		}
	}
	else if (MALO.POSICION.X >= _COLUMNA.POSICION.X - (_COLUMNA.TAMANOCOLUMNA) && MALO.POSICION.X <= _COLUMNA.POSICION.X + (_COLUMNA.TAMANOCOLUMNA) && MALO.POSICION.Z >= _COLUMNA.POSICION.Z +( _COLUMNA.TAMANOCOLUMNA/2) && MALO.POSICION.Z <= _COLUMNA.POSICION.Z + (_COLUMNA.TAMANOCOLUMNA+0.075 ))
	{
		if (sinf(MALO.ANGULO) <= 0)
		{
			MALO.POSICION.Z = _COLUMNA.POSICION.Z + _COLUMNA.TAMANOCOLUMNA;
		}
	}
	else if (MALO.POSICION.Z >= _COLUMNA.POSICION.Z - (_COLUMNA.TAMANOCOLUMNA / 2) && MALO.POSICION.Z <= _COLUMNA.POSICION.Z + (_COLUMNA.TAMANOCOLUMNA / 2) && MALO.POSICION.X > _COLUMNA.POSICION.X -( _COLUMNA.TAMANOCOLUMNA+0.075) && MALO.POSICION.X < _COLUMNA.POSICION.X - (_COLUMNA.TAMANOCOLUMNA / 2))
	{
		if (cosf(MALO.ANGULO) >= 0)
		{
			MALO.POSICION.X = _COLUMNA.POSICION.X - _COLUMNA.TAMANOCOLUMNA;
		}
	}
	else if (MALO.POSICION.Z > _COLUMNA.POSICION.Z - (_COLUMNA.TAMANOCOLUMNA / 2) && MALO.POSICION.Z < _COLUMNA.POSICION.Z + (_COLUMNA.TAMANOCOLUMNA / 2) && MALO.POSICION.X < _COLUMNA.POSICION.X + (_COLUMNA.TAMANOCOLUMNA+0.075) && MALO.POSICION.X > _COLUMNA.POSICION.X + (_COLUMNA.TAMANOCOLUMNA / 2))
	{
		if (cosf(MALO.ANGULO) <= 0)
		{
			MALO.POSICION.X = _COLUMNA.POSICION.X + _COLUMNA.TAMANOCOLUMNA;
		}
	}
	else
	{
		NULL;
	}
}

//Colisión entre el jugador y el zombie:

bool INTERACCIONES::COLISION(JUGADOR& HEROE, ZOMBIE& MALO)
{
	PUNTOSCARTESIANOS dif = HEROE.POSICION - MALO.POSICION;
	float d = dif.Modulo();
	float dentro = d - (float)(HEROE.radio + MALO.radio);

	if (dentro < 0.0)
	{
		return true;
	}
	else
		return false;
}

//Función que cambia el estado del zombie al ser impactado por un disparo

bool INTERACCIONES::COLISION(DISPARO& BALA, ZOMBIE& MALO)
{
	PUNTOSCARTESIANOS dif = MALO.POSICION -BALA.POSICION;
	float d = dif.Modulo();
	float dentro = d - (float)(0.5+MALO.radio);

	if (dentro < 0.0 )
	{
		MALO.impactos++;
		return true;
	}
	else
		return false;
}

//Función que implementa el choque de los disparos con las columnas:

bool INTERACCIONES::COLISION(DISPARO& BALA, COLUMNA& _COLUMNA)
{
	if (BALA.POSICION.X >= _COLUMNA.POSICION.X - (_COLUMNA.TAMANOCOLUMNA / 2) && BALA.POSICION.X <= _COLUMNA.POSICION.X + (_COLUMNA.TAMANOCOLUMNA / 2) && BALA.POSICION.Z >= _COLUMNA.POSICION.Z - (_COLUMNA.TAMANOCOLUMNA / 2) && BALA.POSICION.Z <= _COLUMNA.POSICION.Z + (_COLUMNA.TAMANOCOLUMNA / 2))
	{
		return true;
	}

	else
	{
		return false;
	}

}

//Función que retiene al jugador dentro del mapa: 

void INTERACCIONES::COLISION(JUGADOR& HEROE, TABLERO& SUELO)
{
	if (HEROE.POSICION.X < 0)
	{
		HEROE.POSICION.X = 0;
	}

	else if (HEROE.POSICION.Z < 0)
	{
		HEROE.POSICION.Z = 0;
	}

	else if (HEROE.POSICION.X > SUELO.XMAX)
	{
		HEROE.POSICION.X = SUELO.XMAX;
	}

	else if (HEROE.POSICION.Z > SUELO.ZMAX)
	{
		HEROE.POSICION.Z = SUELO.ZMAX;
	}

	else
	{
		NULL;
	}
}

//Función que retiene al disparo dentro del mapa:

bool INTERACCIONES::COLISION(DISPARO& BALA, TABLERO& _TABLERO)
{
	if (BALA.POSICION.X > _TABLERO.XMAX)
	{
		return true;
	}
	else if (BALA.POSICION.X < 0.0)
	{
		return true;
	}
	else if (BALA.POSICION.Z > _TABLERO.ZMAX)
	{
		return true;
	}
	else if (BALA.POSICION.Z < 0.0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Función que hace que los enemigos sigan al jugador:

void INTERACCIONES::INTELIGENCIA_ARTIFICIAL_ZOMBIE(JUGADOR& HEROE, ZOMBIE& MALO)
{
	if (HEROE.POSICION.X >= MALO.POSICION.X)
	{
		MALO.ANGULO = atanf((HEROE.POSICION.Z - MALO.POSICION.Z) / (HEROE.POSICION.X - MALO.POSICION.X));
	}

	else
	{
		if (HEROE.POSICION.Z <= MALO.POSICION.Z)
		{
			MALO.ANGULO = -((float)3.1416 - atanf((HEROE.POSICION.Z - MALO.POSICION.Z) / (HEROE.POSICION.X - MALO.POSICION.X)));
		}

		else
		{
			MALO.ANGULO = ((float)3.1416 + atanf((HEROE.POSICION.Z - MALO.POSICION.Z) / (HEROE.POSICION.X - MALO.POSICION.X)));
		}
	}
}

//Función que evita que los zombies se atraviesen entre ellos:

void INTERACCIONES::COLISION(ZOMBIE& MALO1, ZOMBIE& MALO2, JUGADOR HEROE)
{
	PUNTOSCARTESIANOS dif = MALO1.POSICION - MALO2.POSICION;
	float d = dif.Modulo();
	float dentro = d - (float)(MALO1.radio+MALO2.radio);

	if (dentro < 0.0)
	{
		if (DISTANCIA_ZOMBIE_HEROE(HEROE, MALO1) < DISTANCIA_ZOMBIE_HEROE(HEROE, MALO2))
		{

			MALO2.POSICION.X = MALO2.POSICION.X + 0.05;
			MALO2.POSICION.Z = MALO2.POSICION.Z + 0.05;


		}
		else if (DISTANCIA_ZOMBIE_HEROE(HEROE, MALO2) < DISTANCIA_ZOMBIE_HEROE(HEROE, MALO1))
		{
			MALO1.POSICION.X = MALO1.POSICION.X + 0.05;
			MALO1.POSICION.Z = MALO1.POSICION.Z + 0.05;

		}
		else
		{
			MALO1.VELOCIDAD = (float)((rand() % 3) + 1) * 0.01;
			MALO2.VELOCIDAD = (float)((rand() % 3) + 1) * 0.01;
		}
	}
}

//Función que calcula la distancia entre un zombie y el jugador:

float INTERACCIONES::DISTANCIA_ZOMBIE_HEROE(JUGADOR& HEROE, ZOMBIE& MALO)
{
	PUNTOSCARTESIANOS dif = HEROE.POSICION - MALO.POSICION;

	float dist = dif.Modulo();
	return dist;
}

//Función que hace que se recoja el bonus tras pasar por encima:

bool INTERACCIONES::COLISION(JUGADOR HEROE, BONUS& REWARD)
{
	PUNTOSCARTESIANOS dif = HEROE.POSICION - REWARD.POSICION;
	float d = dif.Modulo();
	float dentro = d - (float)(1.5);

	if (dentro < 0.0)
	{
		return true;
	}
	else
		return false;
}





