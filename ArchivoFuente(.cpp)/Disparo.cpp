#include<Disparo.h>

void DISPARO::DIBUJA(void)
{
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);
	glTranslatef(POSICION.X, POSICION.Y, POSICION.Z);
	glutSolidSphere(0.5, 20, 20);
	glTranslatef(0, 0, 0);
	glPopMatrix();
}