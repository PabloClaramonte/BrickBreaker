#include <Mundo.h>
#define VB 5.0
#define VJ 30.0

void Mundo::tecla(unsigned char key)
{
	switch (key)
	{
	case 'a':
	{
		HEROE.SetVel(-VJ, 0.0);
		HEROE.DIRECCION = key;
		HEROE.PARADA = key;
		break;
	}
	case 'd':
	{
		HEROE.SetVel(VJ, 0.0);
		HEROE.DIRECCION = key;
		HEROE.PARADA = key;
		break;
	}
	case 'w':
	{
		HEROE.SetVel(0.0, -VJ);
		HEROE.DIRECCION = key;
		HEROE.PARADA = key;
		break;
	}
	case 's':
	{
		HEROE.SetVel(0.0, VJ);
		HEROE.DIRECCION = key;
		HEROE.PARADA = key;
		break;
	}
	case ' ':
	{
		HEROE.SetVel(0.0, 0.0);
		HEROE.PARADA = key;
		break;
	}
	default:

		break;
	}

}
void Mundo::DibujaEjes()
{
	gluLookAt(HEROE.POSICION.X, HEROE.POSICION.Y + 40, HEROE.POSICION.Z + 40, // Posicion de la camara.
		HEROE.POSICION.X, HEROE.POSICION.Y, HEROE.POSICION.Z, // Punto hacia el que mira la camara.
		0, 1, 0); // Vector de autogiro de la camara (No Tocar).   


	//Inicio del codigo de dibujo.

	//Eje cartesiano para aclararnos: X = Rojo; Y = Verde; Z = Azul.
		//Eje X
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(5, 0, 0);
	glEnd();

	//Eje Y 
	glBegin(GL_LINES);
	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 5, 0);
	glEnd();

	//Eje Z
	glBegin(GL_LINES);
	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 5);
	glEnd();
	//Fin eje cartesiano.
}


void Mundo::Dibuja()
{

	CAJA.Dibuja();
	BONUS.Dibuja();
	HEROE.Dibuja();
	
	/*
	if (HEROE.PARADA == ' ')
	{
		BALA.DIRECCION = HEROE.DIRECCION;
	}

	switch (BALA.DIRECCION)
		{
			case 'a':
			{
				BALA.SetVel(-VB, 0.0);
				break;
			}
			case 'd':
			{
				BALA.SetVel(VB, 0.0);
				break;
			}
			case 'w':
			{
				BALA.SetVel(0.0, -VB);
				break;
			}
			case 's':
			{
				BALA.SetVel(0.0, VB);
				break;
			}
			default:
				break;
		}
		
		BALA.Dibuja();

		*/
}

void Mundo::Inicializa()
{
	HEROE.SetPos(10.0, 0.0, 10.0);
	BALA.TIEMPO = 0;
}

void Mundo::Mueve()
{
	HEROE.Mueve(0.025f);
	BALA.Mueve(0.025f);
	Interaccion::Rebote(HEROE, CAJA);
}