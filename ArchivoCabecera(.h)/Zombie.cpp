#include<math.h>
#include <Zombie.h>
#include <freeglut.h>
#include <ETSIDI.h>

/*ZOMBIE::ZOMBIE() 
{
    
    POSICION.Y = 0.0f;
    ANGULO = 0.0f;
    VELOCIDAD = 0.0f;
}*/

ZOMBIE::ZOMBIE(float r, float x, float z , float v , int im): sprite_zombie("imagenes/zombie.png", 4, 2, 100)
{
    sprite_zombie.setCenter(3.5, 0);
    sprite_zombie.setSize(7, 7);
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
   // glColor3f(0.0f, 1.0f, 0.0f);
   // glutSolidSphere(radio, 20, 20);
   // glTranslatef(0, 0, 0);
    if (velocidad * cosf(ANGULO) > 0.01)sprite_zombie.flip(false, false);
    if (velocidad * cosf(ANGULO) < -0.01)sprite_zombie.flip(true, false);
    if ((velocidad * cosf(ANGULO) > 0.01) && (velocidad * cosf(ANGULO) < -0.01))
        sprite_zombie.setState(0);
    else if (sprite_zombie.getState() == 0)
        sprite_zombie.setState(2, false);
    sprite_zombie.draw();

    glPopMatrix();
}

void ZOMBIE::MUEVE(float t)
{
    POSICION.X += (velocidad * cosf(ANGULO));
    POSICION.Z += (velocidad * sinf(ANGULO));
    sprite_zombie.loop();
}

int ZOMBIE::getImpacto()
{
    return impactos;
}

PUNTOSCARTESIANOS ZOMBIE::getPos()
{
    PUNTOSCARTESIANOS POS;
    POS.X = POSICION.X;
    POS.Z = POSICION.Z;
    return POS;
}

