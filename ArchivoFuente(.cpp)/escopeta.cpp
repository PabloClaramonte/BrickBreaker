#include "escopeta.h"


void ESCOPETA::DIBUJA()
{
	glPushMatrix();
	glColor3f(color, 0.0f, 0.0f);
	glTranslatef(POSICION.X, POSICION.Y, POSICION.Z);
	//glutSolidSphere(radio, 20, 20);
	glTranslatef(0, 0, 0);

	sprite.draw();

	glPopMatrix();


	DISPARO::MUEVE(0.025f);
}


