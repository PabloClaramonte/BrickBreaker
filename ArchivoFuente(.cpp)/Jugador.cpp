//Zona de #includes.
#include "Jugador.h"
//Fin zona de #includes.


void JUGADOR::DIBUJA(void)
{
    glPushMatrix();
    glTranslatef(POSICION.X, POSICION.Y, POSICION.Z);
    glColor3f(1.0f, 0.0f, 1.0f);
    glutSolidSphere(2, 20, 20);
    glTranslatef(0, 0, 0);
    glPopMatrix();
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
}


/*
void JUGADOR::MODIFICAR_WSDA(char tecla)
{
    WSAD = tecla;
}

void JUGADOR::MODIFICAR_PREWSDA(char tecla)
{
    PREWSAD = tecla;
}

char JUGADOR::MOSTRAR_WSDA(void)
{
    return WSAD;
}

char JUGADOR::MOSTRAR_PREWSDA(void)
{
    return PREWSAD;
}
*/