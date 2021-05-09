//Zona de #includes.
#include "Jugador.h"
//Fin zona de #includes.

Jugador::Jugador()
{
    DISPARANDO = false;
}

Jugador::~Jugador()
{
}

void Jugador::Dibuja()
{
    // glTranslatef(ValorEspacial_x(), ValorEspacial_y(), ValorEspacial_z());
    glTranslatef(POSICION.X, 0.0, POSICION.Z);
    glColor3f(1.0f, 0.0f, 1.0f);
    glutSolidSphere(2, 20, 20);
    glTranslatef(0, 0, 0);
}


void Jugador::SetVel(float vx, float vz)
{
    VELOCIDAD.X = vx;
    VELOCIDAD.Z = vz;
}

void Jugador::Mueve(float t)
{
    POSICION.X = POSICION.X + VELOCIDAD.X * t;
    POSICION.Z = POSICION.Z + VELOCIDAD.Z * t;
}

void Jugador::SetPos(float px, float py, float pz)
{
    POSICION.X = px;
    POSICION.Y = py;
    POSICION.Z = pz;
}