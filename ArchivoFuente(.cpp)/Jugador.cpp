
#include "Jugador.h"


JUGADOR::JUGADOR() : sprite("imagenes/HEROE.png", 4, 4)
{
    sprite.setCenter(1.5, 1.5);
    sprite.setSize(7, 7);

    POSICION.X = 0.0;
    POSICION.Y = 0.0;
    POSICION.Z = 0.0;

    VELOCIDAD.X = 0.0;
    VELOCIDAD.Y = 0.0;
    VELOCIDAD.Z = 0.0;

    WSAD = NULL;
    PREWSAD = NULL;
    radio = 0.5;
}

JUGADOR::~JUGADOR()
{
}

void JUGADOR::DIBUJA(void)
{
    glPushMatrix();
    glTranslatef(POSICION.X, POSICION.Y, POSICION.Z);
    glColor3f(1.0f, 0.0f, 1.0f);
    //glutSolidSphere(2, 20, 20);
    glTranslatef(0, 0, 0);


    if (VELOCIDAD.X > 0.01)sprite.flip(false, false);
    if (VELOCIDAD.X < -0.01)sprite.flip(true, false);
    if ((VELOCIDAD.X > 0.01) && (VELOCIDAD.X < -0.01))
        sprite.setState(16);
    else if (sprite.getState() == 16)
        sprite.setState(16, false);
    sprite.draw();

    glPopMatrix();
}
void JUGADOR::MUEVE(float t)
{
    POSICION.X = POSICION.X + VELOCIDAD.X * t;
    POSICION.Z = POSICION.Z + VELOCIDAD.Z * t;
    sprite.loop();

}

void JUGADOR::setvel(float vx, float vz)
{
    VELOCIDAD.X = vx;
    VELOCIDAD.Z = vz;
}
