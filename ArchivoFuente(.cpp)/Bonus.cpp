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
void BONUS::MUEVE(float t)
{
    POSICION.X = POSICION.X + VELOCIDAD.X * t;
    POSICION.Z = POSICION.Z + VELOCIDAD.Z * t;
}
void BONUS::SetPos(float ix, float iz)
{
    POSICION.X = ix;
    POSICION.Z = iz;
}

void BONUS::SetVel(float vx, float vz)
{
    VELOCIDAD.X = vx;
    VELOCIDAD.Z = vz;
}



