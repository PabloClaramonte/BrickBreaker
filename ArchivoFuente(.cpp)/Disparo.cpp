#include "Disparo.h"
#include "freeglut.h"

Disparo::Disparo()
{
  
};
void Disparo::SetPos(float posx, float posy,  float posz)
{
    POSICION.X = posx;
    POSICION.Y = posy;
    POSICION.Z = posz;
}
void Disparo::SetVel(float vx, float vz)
{
    VELOCIDAD.X = vx;
    VELOCIDAD.Z = vz;
}

void Disparo::Dibuja()
{
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(POSICION.X, POSICION.Y, POSICION.Z);
    glutSolidSphere(0.25, 20, 20);
    glPopMatrix();
}

void Disparo::Mueve(float t)
{
    POSICION.X = POSICION.X + VELOCIDAD.X * t;
    POSICION.Z = POSICION.Z + VELOCIDAD.Z * t;
}

/*int Disparo::TiempoDisparo()
{
    TIEMPO++;
    return TIEMPO;
}*/
