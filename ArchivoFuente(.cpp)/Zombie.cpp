#include "Zombie.h"

Zombie::Zombie()
{
	velocidad.x = 0.0;
	velocidad.y = 0.0;
}

Zombie::~Zombie()
{
}

void Zombie::Dibuja()
{
    //glColor3ub(rojo, verde, azul); SPRITE
    glTranslatef(posicion.x, posicion.y, 0);
    //glutSolidSphere(radio, 20, 20); SPRITE
    glTranslatef(-posicion.x, -posicion.y, 0);
}