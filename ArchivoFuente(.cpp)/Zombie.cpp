#include "Zombie.h"

Zombie::Zombie()
{
    //posición inicial zombie
    posicion.x = 5.0;
    posicion.y = 0.0;
    posicion.z = 5.0;
    //velocidad inicial zombie
    velocidad.x = 0.0;
	velocidad.y = 0.0;
    velocidad.z = 0.0;
}


Zombie::~Zombie()
{
}


void Zombie::Dibuja()
{
    glColor3ub(0, 255, 0); //En un futuro meteremos un SPRITE
    glTranslatef(posicion.x, 0, posicion.z);
    glutSolidSphere(2, 20, 20); //SPRITE
    glTranslatef(-posicion.x, 0, -posicion.z);
}

void Zombie::Mueve(float t) {
    posicion.x = posicion.x + velocidad.x * t;
    posicion.z = posicion.z + velocidad.z * t;
}

void Zombie::SetVel(float vx, float vz)
{
    velocidad.x = vx;
    velocidad.z = vz;
}