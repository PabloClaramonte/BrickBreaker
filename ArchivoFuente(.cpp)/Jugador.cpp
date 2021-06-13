//Zona de #includes.
#include "Jugador.h"
//Fin zona de #includes.

JUGADOR::JUGADOR() //sprite_lados("imagenes/zombie.png", 4, 2, 100)//, sprite_arriba("imagenes/HEROE_ARRIBA.png", 3), sprite_abajo("imagenes/HEROE_ABAJO.png", 3)
{
    //sprite("imagenes/soldado.png", 5)//

    //sprite_lados.setCenter(3.5, 0);
  //  sprite_lados.setSize(7,7);
   /* sprite_arriba.setCenter(1, 0);
    sprite_arriba.setSize(2, 2);
    sprite_abajo.setCenter(1, 0);
    sprite_abajo.setSize(2, 2);
    sprite.setCenter(1, 0);
    sprite.setSize(1.5, 2);*/

    /*POSICION.X = 0.0;
    POSICION.Y = 0.0;
    POSICION.Z = 0.0;

    VELOCIDAD.X = 0.0;
    VELOCIDAD.Y = 0.0;
    VELOCIDAD.Z = 0.0;*/

    WSAD = NULL;
    PREWSAD = NULL;
    radio = 0.5;
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
    

  /* if (VELOCIDAD.X > 0.01)sprite_lados.flip(false, false);
    if (VELOCIDAD.X < -0.01)sprite_lados.flip(true, false);
    if ((VELOCIDAD.X > 0.01) && (VELOCIDAD.X < -0.01))
        sprite_lados.setState(0);
    else if (sprite_lados.getState() == 0)
        sprite_lados.setState(2, false);
    sprite_lados.draw();
 /*   if (VELOCIDAD.X > 0.01)sprite.flip(false, false);
    if (VELOCIDAD.X < -0.01)sprite.flip(true, false);
    if ((VELOCIDAD.X < 0.01) && (VELOCIDAD.X > -0.01))
        sprite.setState(0);
    else if (sprite.getState() == 0)
        sprite.setState(1, false);
    sprite.draw();*/

    glPopMatrix();
}
void JUGADOR::MUEVE(float t)
{
    POSICION.X = POSICION.X + VELOCIDAD.X * t;
    POSICION.Z = POSICION.Z + VELOCIDAD.Z * t;
   // sprite_abajo.loop();
   // sprite_arriba.loop();
    //sprite_lados.loop();
   //sprite.loop();

}


void JUGADOR::setvel(float vx, float vz)
{
    VELOCIDAD.X = vx;
    VELOCIDAD.Z = vz;
}
