#include "PuntosCartesianos.h"
#include "Jugador.h"
#include <math.h>
#include "freeglut.h"

class Disparo
{
public:

	PuntosCartesianos POSICION;

	int TIEMPO;

	char DIRECCION;

	Disparo()
	{
		POSICION.X = 0.0; POSICION.Y = 0.0; POSICION.Z = 0.0;
	};
	~Disparo() {};

	void Mueve(Jugador HEROE);



	
	void Dibuja(void);

	void ComprobacionDisparo(Jugador& HEROE)
	{
		if (HEROE.DISPARANDO == false)
		{
			POSICION.X = HEROE.POSICION.X;
			POSICION.Y = HEROE.POSICION.Y;
			POSICION.Z = HEROE.POSICION.Z;

		    DIRECCION = HEROE.PREWSDA;

			TIEMPO = 0;
		}

		else
		{
			if (TIEMPO == 10)
			{
				HEROE.DISPARANDO = false;
			}

			else
			{
				NULL;
			}

		}
	
	}

	
	
	
};

