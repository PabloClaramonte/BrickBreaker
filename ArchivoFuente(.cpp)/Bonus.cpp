#include "Bonus.h"
#include "stdlib.h"
#include <math.h>



BONUS::~BONUS()
{

}
BONUS::BONUS()
{
    rojo = verde = azul = 255;
}


// Funcion principal del dibujo del bonus
void BONUS::DIBUJA()
{
    glPushMatrix();
    glTranslatef(POSICION.X, 1.0, POSICION.Z);
    glRotatef(30, 1, 1, 1);
    glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
        rand() / (float)RAND_MAX);//color aleatorio
    glutSolidCube(1.5);
    glPopMatrix();
}
BONUS::BONUS(float ix, float iz)
{
    POSICION.X = ix;
    POSICION.Z = iz;
}
PUNTOSCARTESIANOS BONUS::getPos()
{
    PUNTOSCARTESIANOS POS;
    POS.X = POSICION.X;
    POS.Z = POSICION.Z;
    return POS;
}





