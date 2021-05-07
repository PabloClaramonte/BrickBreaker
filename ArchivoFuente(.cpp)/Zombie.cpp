#include "Zombie.h"

Zombie::Zombie()
{
    //posición inicial zombie
    posicion.X = 5.0;
    posicion.Y = 0.0;
    posicion.Z = 5.0;
    //velocidad inicial zombie
    velocidad.X = 0.0;
	velocidad.Y = 0.0;
    velocidad.Z = 0.0;
}


Zombie::~Zombie()
{
}


void Zombie::Dibuja()
{
    glColor3ub(0, 255, 0); //En un futuro meteremos un SPRITE
    glTranslatef(posicion.X, 0, posicion.Z);
    glutSolidSphere(2, 20, 20); //SPRITE
    glTranslatef(-posicion.X, 0, -posicion.Z);
}

void Zombie::Mueve(float t) {
    posicion.X = posicion.X + velocidad.X * t;
    posicion.Z = posicion.Z + velocidad.Z * t;
}

void Zombie::SetVel(float vx, float vz)
{
    velocidad.X = vx;
    velocidad.Z = vz;
}