#include "Bonus.h"

Bonus::Bonus()
{
    posicion.x = 5.0;
    posicion.y = 1.0;
    posicion.z = 5.0;
    lado = 1.0;
}

Bonus::~Bonus()
{
}

void Bonus::Dibuja()
{
    glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 0);
    glRotatef(30, 1, 1, 1);
    glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
        rand() / (float)RAND_MAX);//color aleatorio
    glutSolidCube(lado);
    glPopMatrix();
}