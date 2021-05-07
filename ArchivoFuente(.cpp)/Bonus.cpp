#include "Bonus.h"

Bonus::Bonus()
{
    posicion.X = 5.0;
    posicion.Y = 1.0;
    posicion.Z = 5.0;
    lado = 1.0;
}

Bonus::~Bonus()
{
}

void Bonus::Dibuja()
{
    glPushMatrix();
    glTranslatef(posicion.X, posicion.Y, 0);
    glRotatef(30, 1, 1, 1);
    glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
        rand() / (float)RAND_MAX);//color aleatorio
    glutSolidCube(lado);
    glPopMatrix();
}