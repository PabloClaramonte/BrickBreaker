#include "Zombie.h"

Zombie::Zombie():PuntosCartesianos()
{
    //posición inicial zombie
    posicion.x = 10.0;
    posicion.y = 0.0;
    posicion.z = 10.0;
    //velocidad inicial zombie
    velocidad.x = 1.0;
	velocidad.y = 0.0;
}


Zombie::~Zombie()
{
}


void Zombie::Dibuja()
{
    glColor3ub(0, 255, 0); //En un futuro meteremos un SPRITE
    glTranslatef(posicion.x, posicion.y, 0);
    glutSolidSphere(2, 20, 20); //SPRITE
    glTranslatef(-posicion.x, -posicion.y, 0);
}

void Zombie::Mueve(float t) {

}