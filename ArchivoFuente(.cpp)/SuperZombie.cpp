#include "SuperZombie.h"

void SUPERZOMBIE::DIBUJA()
{
    glPushMatrix();
    glTranslatef(POSICION.X, POSICION.Y, POSICION.Z);
   // glColor3f(color, 0.0f, color);
  //  glutSolidSphere(radio, 20, 20);
   // glTranslatef(0, 0, 0);
   // 

    if (velocidad * cosf(ANGULO) > 0.01)sprite_superzombie.flip(false, false);
    if (velocidad * cosf(ANGULO) < -0.01)sprite_superzombie.flip(true, false);
    if ((velocidad * cosf(ANGULO) > 0.01) && (velocidad * cosf(ANGULO) < -0.01))
        sprite_superzombie.setState(0);
    else if (sprite_superzombie.getState() == 0)
        sprite_superzombie.setState(2, false);
    sprite_superzombie.draw();
    glPopMatrix();
}
void SUPERZOMBIE::MUEVE(float t)
{
    POSICION.X += (velocidad * cosf(ANGULO));
    POSICION.Z += (velocidad * sinf(ANGULO));
    sprite_superzombie.loop();
}
