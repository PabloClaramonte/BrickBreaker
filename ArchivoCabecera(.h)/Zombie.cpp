#include<math.h>
#include <Zombie.h>
#include <freeglut.h>
#include <ETSIDI.h>

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
        //Cambia de aspecto para que se vea que lo has matado. SPRITE CHARCO SANGRE
        
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/sangre.png").id);
        glDisable(GL_LIGHTING);
        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);

		glTexCoord3d(0, 1, 0); glVertex3f(POSICION.X - 2, 0.01, POSICION.Z - 2);
		glTexCoord3d(1, 1, 0); glVertex3f(POSICION.X + 2, 0.01, POSICION.Z - 2);
		glTexCoord3d(1, 0, 0); glVertex3f(POSICION.X + 2, 0.01, POSICION.Z + 2);
		glTexCoord3d(0, 0, 0); glVertex3f(POSICION.X - 2, 0.5, POSICION.Z + 2);

        glEnd();
        glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);
   
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