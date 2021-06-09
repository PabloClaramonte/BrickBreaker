#include <Tablero.h>

TABLERO::TABLERO(float x, float z)
{
	XMAX = x;
	ZMAX = z;
}

void TABLERO::DIBUJA(void)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);

	glTexCoord3d(0, 1, 0); glVertex3f(0, 0, 0);
	glTexCoord3d(1, 1, 0); glVertex3f(XMAX, 0, 0);
	glTexCoord3d(1, 0, 0); glVertex3f(XMAX, 0, ZMAX);
	glTexCoord3d(0, 0, 0); glVertex3f(0, 0, ZMAX);

	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}



