//Zona de #includes.
#include "Jugador.h"
//Fin zona de #includes.


JUGADOR::JUGADOR()
{
    POSICION.X = 0.0f;
    POSICION.Y = 0.0f;
    POSICION.Z = 0.0f;
    WSAD = NULL;
    PREWSAD = NULL;
    VELOCIDAD = 0;

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

    if (VELOCIDAD > 0.01)sprite.flip(false, false);
    if (VELOCIDAD < -0.01)sprite.flip(true, false);
    if ((VELOCIDAD < 0.01) && (VELOCIDAD > -0.01))
        sprite.setState(0);
    else if (sprite.getState() == 0)
        sprite.setState(1, false);
    sprite.draw();
}

void JUGADOR::MUEVE(void)
{
    if (WSAD == 'w')
    {
        POSICION.Z -= VELOCIDAD;
    }

    else if (WSAD == 's')
    {
        POSICION.Z += VELOCIDAD;
    }

    else if (WSAD == 'a')
    {
        POSICION.X -= VELOCIDAD;
    }

    else if (WSAD == 'd')
    {
        POSICION.X += VELOCIDAD;
    }

    else
    {
        NULL;
    }

    sprite.loop();
}

char JUGADOR::MOSTRAR_WSDA(void)
{
    return 0;
}
