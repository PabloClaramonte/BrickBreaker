#include "Disparo.h"

#include "freeglut.h"


Disparo::Disparo()
{
	rojo = 0;
	verde = 0;
	azul = 0;

	posicion.x = 0.0;
	posicion.z = 0.0;
	velocidad.x = 0.0;
	velocidad.z = 0.0;
}

Disparo::~Disparo()
{
}

void Disparo::Dibuja()
{
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20); //hay que incluir el sprite
	glPopMatrix();
}
//tendremos obligatoriamente que saber en que direccion mira para ponerle direccion y sentido
//al disparo y despues añadimos las mierda de funciones que tiene guille en puntoscartesianos.h
void Disparo::getDir(unsigned char key)
{
	if (key == 'a')
	{
		velocidad.x = -10.0;
		velocidad.z = 0;
	}
	if (key == 'd')
	{
		velocidad.x = 10.0;
		velocidad.z = 0;
	}
	if (key == 'w')
	{
		velocidad.z = 10.0;
		velocidad.x = 0;
	}
	if (key == 's')
	{
		velocidad.z = -10.0;
		velocidad.x = 0;
	}
}

void Disparo::Mueve(float t)
{
	posicion = posicion +  velocidad * t;
}
void Disparo::SetPos(float ix, float iy)
{
	posicion.x = ix;
	posicion.y = iy;
}