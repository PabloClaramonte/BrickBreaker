//Zona de #includes.
#include "Jugador.h"
//Fin zona de #includes.

JUGADOR::JUGADOR()
{
    POSICION.X = 0.0;
    POSICION.Y = 0.0;
    POSICION.Z = 0.0;

    VELOCIDAD.X = 0.0;
    VELOCIDAD.Y = 0.0;

    WSAD = NULL;
    PREWSAD = NULL;

    sprite.setCenter(1, 0);
    sprite.setSize(5, 5);
}

JUGADOR::~JUGADOR()
{
}

void JUGADOR::DIBUJA(void)
{
    glPushMatrix();
    glTranslatef(POSICION.X, POSICION.Y, POSICION.Z);
    glColor3f(1.0f, 0.0f, 1.0f);
    glutSolidSphere(2, 20, 20);
    glTranslatef(0, 0, 0);
    glPopMatrix();

    /*if (VELOCIDAD > 0.01)sprite.flip(false, false);
    if (VELOCIDAD < -0.01)sprite.flip(true, false);
    if ((VELOCIDAD < 0.01) && (VELOCIDAD > -0.01))
        sprite.setState(0);
    else if (sprite.getState() == 0)
        sprite.setState(1, false);
    sprite.draw();*/
}
void JUGADOR::Mueve(float t)
{
    POSICION.X = POSICION.X + VELOCIDAD.X * t;
    POSICION.Z = POSICION.Z + VELOCIDAD.Z * t;
}

void JUGADOR::setvel(float vx, float vz)
{
    VELOCIDAD.X = vx;
    VELOCIDAD.Z = vz;
}
