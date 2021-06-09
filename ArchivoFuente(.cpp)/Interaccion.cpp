#include "Interaccion.h"
#include "math.h"

//Funci�n que evita que el jugador atraviese las columnas:

bool INTERACCIONES::INTERACCION_JUGADOR_COLUMNA(JUGADOR& HEROE, COLUMNA& _COLUMNA)
{
	if (HEROE.POSICION.X > _COLUMNA.POSICION.X - (_COLUMNA.TAMANOCOLUMNA / 2) && HEROE.POSICION.X < _COLUMNA.POSICION.X + (_COLUMNA.TAMANOCOLUMNA / 2) && HEROE.POSICION.Z < _COLUMNA.POSICION.Z + _COLUMNA.TAMANOCOLUMNA && HEROE.POSICION.Z > _COLUMNA.POSICION.Z + (_COLUMNA.TAMANOCOLUMNA / 2))
	{
		HEROE.POSICION.Z = _COLUMNA.POSICION.Z + _COLUMNA.TAMANOCOLUMNA;
		return true;
	}
	else if (HEROE.POSICION.X > _COLUMNA.POSICION.X - (_COLUMNA.TAMANOCOLUMNA / 2) && HEROE.POSICION.X < _COLUMNA.POSICION.X + (_COLUMNA.TAMANOCOLUMNA / 2) && HEROE.POSICION.Z > _COLUMNA.POSICION.Z - _COLUMNA.TAMANOCOLUMNA && HEROE.POSICION.Z < _COLUMNA.POSICION.Z + (_COLUMNA.TAMANOCOLUMNA / 2))
	{
		HEROE.POSICION.Z = _COLUMNA.POSICION.Z - _COLUMNA.TAMANOCOLUMNA;
		return true;
	}
	else if (HEROE.POSICION.Z > _COLUMNA.POSICION.Z - (_COLUMNA.TAMANOCOLUMNA / 2) && HEROE.POSICION.Z < _COLUMNA.POSICION.Z + (_COLUMNA.TAMANOCOLUMNA / 2) && HEROE.POSICION.X > _COLUMNA.POSICION.X - _COLUMNA.TAMANOCOLUMNA && HEROE.POSICION.X < _COLUMNA.POSICION.X - (_COLUMNA.TAMANOCOLUMNA / 2))
	{
		HEROE.POSICION.X = _COLUMNA.POSICION.X - _COLUMNA.TAMANOCOLUMNA;
		return true;
	}
	else if (HEROE.POSICION.Z > _COLUMNA.POSICION.Z - (_COLUMNA.TAMANOCOLUMNA / 2) && HEROE.POSICION.Z < _COLUMNA.POSICION.Z + (_COLUMNA.TAMANOCOLUMNA / 2) && HEROE.POSICION.X < _COLUMNA.POSICION.X + _COLUMNA.TAMANOCOLUMNA && HEROE.POSICION.X > _COLUMNA.POSICION.X + (_COLUMNA.TAMANOCOLUMNA / 2))
	{
		HEROE.POSICION.X = _COLUMNA.POSICION.X + _COLUMNA.TAMANOCOLUMNA;
		return true;
	}
	else
	{
		return false;
	}
}

//Funci�n que evita que los zombies atraviesen las columnas:

void INTERACCIONES::INTERACCION_ZOMBIE_COLUMNA(ZOMBIE& MALO, COLUMNA& _COLUMNA)
{
	if (MALO.POSICION.X > _COLUMNA.POSICION.X - (_COLUMNA.TAMANOCOLUMNA / 2) && MALO.POSICION.X < _COLUMNA.POSICION.X + (_COLUMNA.TAMANOCOLUMNA / 2) && MALO.POSICION.Z < _COLUMNA.POSICION.Z + _COLUMNA.TAMANOCOLUMNA && MALO.POSICION.Z > _COLUMNA.POSICION.Z + (_COLUMNA.TAMANOCOLUMNA / 2))
	{
		MALO.POSICION.Z = _COLUMNA.POSICION.Z + _COLUMNA.TAMANOCOLUMNA;
	}
	else if (MALO.POSICION.X > _COLUMNA.POSICION.X - (_COLUMNA.TAMANOCOLUMNA / 2) && MALO.POSICION.X < _COLUMNA.POSICION.X + (_COLUMNA.TAMANOCOLUMNA / 2) && MALO.POSICION.Z > _COLUMNA.POSICION.Z - _COLUMNA.TAMANOCOLUMNA && MALO.POSICION.Z < _COLUMNA.POSICION.Z + (_COLUMNA.TAMANOCOLUMNA / 2))
	{
		MALO.POSICION.Z = _COLUMNA.POSICION.Z - _COLUMNA.TAMANOCOLUMNA;
	}
	else if (MALO.POSICION.Z > _COLUMNA.POSICION.Z - (_COLUMNA.TAMANOCOLUMNA / 2) && MALO.POSICION.Z < _COLUMNA.POSICION.Z + (_COLUMNA.TAMANOCOLUMNA / 2) && MALO.POSICION.X > _COLUMNA.POSICION.X - _COLUMNA.TAMANOCOLUMNA && MALO.POSICION.X < _COLUMNA.POSICION.X - (_COLUMNA.TAMANOCOLUMNA / 2))
	{
		MALO.POSICION.X = _COLUMNA.POSICION.X - _COLUMNA.TAMANOCOLUMNA;
	}
	else if (MALO.POSICION.Z > _COLUMNA.POSICION.Z - (_COLUMNA.TAMANOCOLUMNA / 2) && MALO.POSICION.Z < _COLUMNA.POSICION.Z + (_COLUMNA.TAMANOCOLUMNA / 2) && MALO.POSICION.X < _COLUMNA.POSICION.X + _COLUMNA.TAMANOCOLUMNA && MALO.POSICION.X > _COLUMNA.POSICION.X + (_COLUMNA.TAMANOCOLUMNA / 2))
	{
		MALO.POSICION.X = _COLUMNA.POSICION.X + _COLUMNA.TAMANOCOLUMNA;
	}
	else
	{
		NULL;
	}
}

bool INTERACCIONES::INTERACCION_JUGADOR_ZOMBIE(JUGADOR& HEROE, ZOMBIE& MALO)
{
	if (HEROE.POSICION.X > MALO.POSICION.X - 2 && HEROE.POSICION.X < MALO.POSICION.X + 2 && HEROE.POSICION.Z > MALO.POSICION.Z - 2 && HEROE.POSICION.Z < MALO.POSICION.Z + 2 && MALO.VIVO)
	{
		MALO.VIVO = false; //El estado del zombie pasa a muerto.
		ETSIDI::play("sonidos/disparo.wav"); //Sonido jocoso
	}

	else
	{
		NULL;
	}

	return MALO.VIVO;
}

//Funci�n que cambia el estado del zombie al ser impactado por un disparo

bool INTERACCIONES::INTERACCION_BALA_ZOMBIE(DISPARO& BALA, ZOMBIE& MALO)
{
	if (BALA.POSICION.X > MALO.POSICION.X - 2.0f && BALA.POSICION.X < MALO.POSICION.X + 2.0f && BALA.POSICION.Z > MALO.POSICION.Z - 2.0f && BALA.POSICION.Z < MALO.POSICION.Z + 2.0f)
	{
		return true; //El estado del zombie pasa a muerto.
		//MALO.VIVO = FALSE;
		//ETSIDI::play("sonidos/impacto.wav"); //Sonido jocoso
	}
}

//Funci�n que implementa el choque de los disparos con las columnas:

bool INTERACCIONES::INTERACCION_BALA_COLUMNA(DISPARO& BALA, COLUMNA& _COLUMNA)
{
	if (BALA.POSICION.X > _COLUMNA.POSICION.X - (_COLUMNA.TAMANOCOLUMNA / 4) && BALA.POSICION.X < _COLUMNA.POSICION.X + (_COLUMNA.TAMANOCOLUMNA / 4) && BALA.POSICION.Z < _COLUMNA.POSICION.Z + _COLUMNA.TAMANOCOLUMNA && BALA.POSICION.Z > _COLUMNA.POSICION.Z + (_COLUMNA.TAMANOCOLUMNA / 4))
	{
		return true;
	}
	else if (BALA.POSICION.X > _COLUMNA.POSICION.X - (_COLUMNA.TAMANOCOLUMNA / 4) && BALA.POSICION.X < _COLUMNA.POSICION.X + (_COLUMNA.TAMANOCOLUMNA / 4) && BALA.POSICION.Z > _COLUMNA.POSICION.Z - _COLUMNA.TAMANOCOLUMNA && BALA.POSICION.Z < _COLUMNA.POSICION.Z + (_COLUMNA.TAMANOCOLUMNA / 4))
	{
		return true;
	}
	else if (BALA.POSICION.Z > _COLUMNA.POSICION.Z - (_COLUMNA.TAMANOCOLUMNA / 4) && BALA.POSICION.Z < _COLUMNA.POSICION.Z + (_COLUMNA.TAMANOCOLUMNA / 4) && BALA.POSICION.X > _COLUMNA.POSICION.X - _COLUMNA.TAMANOCOLUMNA && BALA.POSICION.X < _COLUMNA.POSICION.X - (_COLUMNA.TAMANOCOLUMNA / 4))
	{
		return true;
	}
	else if (BALA.POSICION.Z > _COLUMNA.POSICION.Z - (_COLUMNA.TAMANOCOLUMNA / 4) && BALA.POSICION.Z < _COLUMNA.POSICION.Z + (_COLUMNA.TAMANOCOLUMNA / 4) && BALA.POSICION.X < _COLUMNA.POSICION.X + _COLUMNA.TAMANOCOLUMNA && BALA.POSICION.X > _COLUMNA.POSICION.X + (_COLUMNA.TAMANOCOLUMNA / 4))
	{
		return true;
	}
	else
	{
		return false;
	}

}

void INTERACCIONES::INTERACCION_JUGADOR_TABLERO(JUGADOR& HEROE, TABLERO& SUELO)
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

bool INTERACCIONES::INTERACCION_BALA_TABLERO(DISPARO& BALA, TABLERO& _TABLERO)
{
	if (BALA.POSICION.X > _TABLERO.XMAX)
	{
		//BALA.POSICION.X = _TABLERO.XMAX;
		return true;
	}
	else if (BALA.POSICION.X < 0.0)
	{
		//BALA.POSICION.X = 0.0;
		return true;
	}
	else if (BALA.POSICION.Z > _TABLERO.ZMAX)
	{
		//BALA.POSICION.Z = _TABLERO.ZMAX;
		return true;
	}
	else if (BALA.POSICION.Z < 0.0)
	{
		//BALA.POSICION.Z = 0.0;
		return true;
	}
	else
	{
		return false;
	}
}

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
			MALO.ANGULO = -(3.1416 - atanf((HEROE.POSICION.Z - MALO.POSICION.Z) / (HEROE.POSICION.X - MALO.POSICION.X)));
		}

		else
		{
			MALO.ANGULO = (3.1416 + atanf((HEROE.POSICION.Z - MALO.POSICION.Z) / (HEROE.POSICION.X - MALO.POSICION.X)));
		}
	}
}

void INTERACCIONES::CHOQUE_ENTRE_ZOMBIES(ZOMBIE& MALO1, ZOMBIE& MALO2)
{
	if (MALO1.VIVO) 
	{
		if (MALO1.POSICION.X > MALO2.POSICION.X - 2 && MALO1.POSICION.X < MALO2.POSICION.X + 2 && MALO1.POSICION.Z < MALO2.POSICION.Z + 2 && MALO1.POSICION.Z > MALO2.POSICION.Z + 2)
		{
			MALO1.POSICION.Z = MALO2.POSICION.Z + 2;
		}
		else if (MALO1.POSICION.X > MALO2.POSICION.X - 2 && MALO1.POSICION.X < MALO2.POSICION.X + 2 && MALO1.POSICION.Z > MALO2.POSICION.Z - 2 && MALO1.POSICION.Z < MALO2.POSICION.Z + 2)
		{
			MALO1.POSICION.Z = MALO2.POSICION.Z - 2;
		}
		else if (MALO1.POSICION.Z > MALO2.POSICION.Z - 2 && MALO1.POSICION.Z < MALO2.POSICION.Z + 2 && MALO1.POSICION.X > MALO2.POSICION.X - 2 && MALO1.POSICION.X < MALO2.POSICION.X - 2)
		{
			MALO1.POSICION.X = MALO2.POSICION.X - 2;
		}
		else if (MALO1.POSICION.Z > MALO2.POSICION.Z - 2 && MALO1.POSICION.Z < MALO2.POSICION.Z + 2 && MALO1.POSICION.X < MALO2.POSICION.X + 2 && MALO1.POSICION.X > MALO2.POSICION.X + 2)
		{
			MALO1.POSICION.X = MALO2.POSICION.X + 2;
		}
		else
		{
			NULL;
		}
	}
	else
	{
		NULL;
	}
}




