#include<math.h>
#include <Zombie.h>
#include <freeglut.h>
#include <ETSIDI.h>

ZOMBIE::ZOMBIE()
{
    POSICION.Y = 0.0f;
    ANGULO = 0.0f;
    VELOCIDAD = 0.0f;
}

ZOMBIE::ZOMBIE(float x, float z, float v)
{
    POSICION.X = x;
    POSICION.Z = z;
    VELOCIDAD = v;

    ANGULO = 0.0f;
}

ZOMBIE::~ZOMBIE()
{
}

void ZOMBIE::DIBUJA(void)
{
    glPushMatrix();
    glTranslatef(POSICION.X, POSICION.Y, POSICION.Z);
    glColor3f(0.0f, 1.0f, 0.0f);
    glutSolidSphere(2, 20, 20);
    glTranslatef(0, 0, 0);
    glPopMatrix();
}

void ZOMBIE::MUEVE(float t)
{
    POSICION.X += (VELOCIDAD * cosf(ANGULO));
    POSICION.Z += (VELOCIDAD *sinf(ANGULO));
}

