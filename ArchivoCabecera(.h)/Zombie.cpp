#include<math.h>
#include <Zombie.h>
#include <freeglut.h>

ZOMBIE::ZOMBIE()
{
    VIVO = true;

    POSICION.X = 0.0;
    POSICION.Y = 0.0;
    POSICION.Z = 0.0;
    VELOCIDAD = 0.0;
    ANGULO = 0.0;
}

ZOMBIE::~ZOMBIE()
{
}

void ZOMBIE::DIBUJA(void)
{
    if (VIVO) {
        glPushMatrix();
        glTranslatef(POSICION.X, POSICION.Y, POSICION.Z);
        glColor3f(0.0f, 1.0f, 0.0f);
        glutSolidSphere(2, 20, 20);
        glTranslatef(0, 0, 0);
        glPopMatrix();
    }
    else {
        //Cambia de aspecto para que se vea que lo has matado. Será SPRITE CHARCO SANGRE
        glPushMatrix();
        glTranslatef(POSICION.X, POSICION.Y, POSICION.Z);
        glColor3f(0.0f, 1.0f, 1.0f);
        glutSolidSphere(0.5, 20, 20);
        glTranslatef(0, 0, 0);
        glPopMatrix();
    }
}

void ZOMBIE::MUEVE(void)
{
    if (VIVO)
    {
        POSICION.X += (VELOCIDAD * cosf(ANGULO));
        POSICION.Z += (VELOCIDAD *sinf(ANGULO));
    }

    else
    {
        NULL;
    }
}