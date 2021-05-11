#include<math.h>

#include <Zombie.h>
#include <freeglut.h>

void ZOMBIE::DIBUJA(void)
{
    glPushMatrix();
    glTranslatef(POSICION.X, POSICION.Y, POSICION.Z);
    glColor3f(0.0f, 1.0f, 0.0f);
    glutSolidSphere(2, 20, 20);
    glTranslatef(0, 0, 0);
    glPopMatrix();
}

void ZOMBIE::MUEVE(void)
{
    if (VIVO)
    {
        POSICION.X += (VELOCIDAD *cosf(ANGULO));
        POSICION.Z += (VELOCIDAD *sinf(ANGULO));
    }

    else
    {
        NULL;
    }
}