#include "Zombie.h"

Zombie::Zombie():PuntosCartesianos()
{
	//velocidad.x = 0.0;
	//velocidad.y = 0.0;
}


Zombie::~Zombie()
{
}


void Zombie::Dibuja()
{
    glColor3ub(0, 255, 0); //SPRITE
    glTranslatef(posicion.x, posicion.y, 0);
    glutSolidSphere(0.5, 20, 20); //SPRITE
    glTranslatef(-posicion.x, -posicion.y, 0);
}

void Zombie::Mueve(float t) {

}