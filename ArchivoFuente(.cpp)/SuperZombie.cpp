#include "SuperZombie.h"

void SUPERZOMBIE::DIBUJA()
{
    glPushMatrix();
    glTranslatef(POSICION.X, POSICION.Y, POSICION.Z);
    glColor3f(color, 0.0f, color);
    glutSolidSphere(radio, 20, 20);
    glTranslatef(0, 0, 0);
    glPopMatrix();
}
