//Zona de #includes.
#include "Jugador.h"
//Fin zona de #includes.

Jugador::Jugador()
{
    POSICION.X = POSICION.Y = POSICION.Z = 0.0f;
   
}

Jugador::~Jugador()
{
}

void Jugador::Dibuja()
{
   // glTranslatef(ValorEspacial_x(), ValorEspacial_y(), ValorEspacial_z());
    glTranslatef(POSICION.X, POSICION.Y, POSICION.Z);
    glColor3f(1.0f, 0.0f, 1.0f);
    glutSolidSphere(2, 20, 20);
    glTranslatef(0, 0, 0);
}

void Jugador::SetVel(float vel)
{
    VELOCIDAD = vel;
}

void Jugador::SetWSDA(unsigned char tecla)
{
    if (tecla == 'w' || tecla == 's' || tecla == 'd' || tecla == 'a')
    {
        WSDA = tecla;
        PREWSDA = tecla;
    }

    else if (tecla == ' ')
    {
        if (DISPARANDO == false)
        {
            DISPARANDO = true;
        }

        else
        {
            NULL;
        }

        WSDA = NULL;
    }

    else
    {
        WSDA = NULL;
    }

}

void Jugador::Mueve(void)
{
    switch (WSDA)
    {
        //DUDA: Queremos que se detenga al pulsar dos veces la misma tecla
    case 'w':
    {
        POSICION.Z = POSICION.Z - VELOCIDAD;
        break;
    }

    case 's':
    {
        POSICION.Z = POSICION.Z + VELOCIDAD;
        break;
    }

    case 'a':
    {
        POSICION.X = POSICION.X - VELOCIDAD;
        break;
    }

    case 'd': 
    {
        POSICION.X = POSICION.X + VELOCIDAD;
        break;
    }

    default:
    {
        break;
    }

    }
}

char Jugador::DarPREWSDA(void)
{
    return PREWSDA;
}
