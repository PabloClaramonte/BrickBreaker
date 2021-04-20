#include "Disparo.h"

Disparo::Disparo()
{
	rojo = 0;
	verde = 0;
	azul = 0;

	velocidad.x = 0.0;
	velocidad.y = 0.0;
}

Disparo::~Disparo()
{
}

void Disparo::Dibuja()
{
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	//glutSolidSphere(radio, 20, 20); hay que incluir el sprite
	glPopMatrix();
}