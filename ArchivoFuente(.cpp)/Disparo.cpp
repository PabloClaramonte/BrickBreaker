#include "Disparo.h"
#include "freeglut.h"


Disparo::Disparo()
{
	rojo = 0;
	verde = 0;
	azul = 0;

	radio = 0.5;

	posicion.x = -5.0;
	posicion.y = 0.0;
	posicion.z = 0.0;

	velocidad.x = 0.0;
	velocidad.y = 0.0;
	velocidad.z = 0.0;

	v_ang = 0.0;
	angulo = 0.0;
	dist = 5.0;
}

Disparo::~Disparo()
{
}

void Disparo::Dibuja()
{
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, 0, posicion.z);
	glutSolidSphere(radio, 20, 20); //hay que incluir el sprite
	glPopMatrix();
}

void Disparo::SetVel(float vx, float vz)
{
	velocidad.x = vx;
	velocidad.z = vz;
}

void Disparo::SetVelAng(float w)
{
	v_ang = w;
}

//tendremos obligatoriamente que saber en que direccion mira para ponerle direccion y sentido
//al disparo y despues añadimos las mierda de funciones que tiene guille en puntoscartesianos.h
void Disparo::tecla(unsigned char key)
{
	switch (key)
	{
		case 'j':
			SetVelAng(-5.0);
			break;
		case 'l':
			SetVelAng(5.0f);
			break;
		case 'k':
			SetVelAng(0.0f);
			break;
	}
}


void Disparo::direccion(float t)
{
	float dist = sqrt((posicion.x - j.posicion.x) * (posicion.x - j.posicion.x) + (posicion.z - j.posicion.z) * (posicion.z - j.posicion.z));
	angulo= atan2(posicion.z-j.posicion.z, posicion.x-j.posicion.x);

	angulo = angulo + v_ang * t;
	posicion.x = dist * cos(angulo);
	posicion.z = dist * sin(angulo);
}
void Disparo::SetPos(float ix, float iz)
{
	posicion.x = ix;
	posicion.z = iz;
}