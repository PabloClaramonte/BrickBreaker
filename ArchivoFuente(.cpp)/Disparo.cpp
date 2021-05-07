#include "Disparo.h"
#include "freeglut.h"


void Disparo::Mueve(Jugador HEROE)
{
    if (HEROE.DISPARANDO == true)
    {
        switch (DIRECCION)
        {

        case 'w':
        {
            POSICION.Z=POSICION.Z-2;
            TIEMPO++;
            break;
        }

        case 's':
        {
            POSICION.Z = POSICION.Z + 2;
            TIEMPO++;
            break;
        }

        case'd':
        {
            POSICION.X = POSICION.X + 2;
            TIEMPO++;
            break;
        }

        case 'a':
        {
            POSICION.X = POSICION.X - 2;
            TIEMPO++;
            break;
        }

        default:
        {
            break;
        }

        }
    }

    else
    {
        NULL;
    }

}




void Disparo::Dibuja(void)
{
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(POSICION.X, POSICION.Y, POSICION.Z);
    glutSolidSphere(0.25, 20, 20);
    glPopMatrix();
}
