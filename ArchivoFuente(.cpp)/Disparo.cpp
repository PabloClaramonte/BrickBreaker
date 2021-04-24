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

//tendremos obligatoriamente que saber en que direccion mira para ponerle direccion y sentido
//al disparo y despues añadimos las mierda de funciones que tiene guille en puntoscartesianos.h
void Disparo::tecla(unsigned char key)
{
    switch (key)
    {
        //DUDA: Queremos que se detenga al pulsar dos veces la misma tecla
    case 'w':
    {
        SetVel(20.0, 0.0);
        break;
    }
    case 's':
    {
        SetVel(-20.0, 0.0);
        break;
    }
    case 'a':
    {
        SetVel(0.0, -20.0);
        break;
    }
    case 'd':
    {
        SetVel(0.0, 20.0);;
        break;
    }
    case ' ':
        SetVel(0.0, 0.0);
        break;
    }
}

void Disparo::Mueve(float t)
{
	posicion.x = posicion.x + velocidad.x * t;
	posicion.z = posicion.z + velocidad.z * t;
}
void Disparo::SetPos(float ix, float iz)
{
	posicion.x = ix;
	posicion.z = iz;
}