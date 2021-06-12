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

ZOMBIE::ZOMBIE(float r, float x, float z , float v , int im)
{
    POSICION.X = x;
    POSICION.Z = z;
    velocidad= v;
    radio = r;
    impactos = im;

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
    glutSolidSphere(radio, 20, 20);
    glTranslatef(0, 0, 0);
    glPopMatrix();
}

void ZOMBIE::MUEVE(float t)
{
    POSICION.X += (velocidad * cosf(ANGULO));
    POSICION.Z += (velocidad * sinf(ANGULO));
}

int ZOMBIE::getImpacto()
{
    return impactos;
}

PUNTOSCARTESIANOS ZOMBIE::getVel()
{
    PUNTOSCARTESIANOS VEL;
    VEL.X = velocidad * cosf(ANGULO);
    VEL.Z = velocidad * sinf(ANGULO);
    return VEL;
}

