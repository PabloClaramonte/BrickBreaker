#include <Mundo.h>

void Mundo::tecla(unsigned char key)
{
	switch (key)
	{
	case 'a':
	{
		HEROE.SetVel(-10.0, 0.0);
		HEROE.DIRECCION = key;
		HEROE.PARADA = key;
		break;
	}
	case 'd':
	{
		HEROE.SetVel(10.0, 0.0);
		HEROE.DIRECCION = key;
		HEROE.PARADA = key;
		break;
	}
	case 'w':
	{
		HEROE.SetVel(0.0, -10.0);
		HEROE.DIRECCION = key;
		HEROE.PARADA = key;
		break;
	}
	case 's':
	{
		HEROE.SetVel(0.0, 10.0);
		HEROE.DIRECCION = key;
		HEROE.PARADA = key;
		break;
	}
	case ' ':
	{
		HEROE.SetVel(0.0, 0.0);
		HEROE.DISPARANDO = true;
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
	
	
	if (HEROE.DISPARANDO == true && HEROE.PARADA==' ')
	{
		BALA.DIRECCION = HEROE.DIRECCION;		
	}
	switch (BALA.DIRECCION)
		{
		case 'a':
		{
		BALA.SetVel(-2.0, 0.0);
		break;
		}
		case 'd':
		{
		BALA.SetVel(2.0, 0.0);
		break;
		}
		case 'w':
		{
		BALA.SetVel(0.0, -2.0);
		break;
		}
		case 's':
		{
		BALA.SetVel(0.0, 2.0);
		break;
		}
		default:
		break;
		}
		BALA.Dibuja();
}

void Mundo::Inicializa()
{

	HEROE.SetPos(0.0, 0.0, 0.0);
	BALA.TIEMPO = 0;

}

void Mundo::Mueve()
{
	HEROE.Mueve(0.025f);
	BALA.Mueve(0.025f);
}