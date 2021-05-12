#include<Disparo.h>

DISPARO::DISPARO()
{
	POSICION.X = 0.0;
	POSICION.Y = 0.0;
	POSICION.Z = 0.0;

	DIRECCION = NULL;
	TIEMPODISPARO = 0;
	VELOCIDAD = 0;
}

DISPARO::~DISPARO()
{
}

void DISPARO::DIBUJA(void)
{
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);
	glTranslatef(POSICION.X, POSICION.Y, POSICION.Z);
	glutSolidSphere(0.5, 20, 20);
	glTranslatef(0, 0, 0);
	glPopMatrix();
}