#include <Tablero.h>

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
	
	/*glVertex3f(0, 0, 0);
	glVertex3f(XMAX, 0, 0);
	glVertex3f(XMAX, 0, ZMAX);
	glVertex3f(0, 0, ZMAX);
	glVertex3f(0, 0, 0);*/

	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}


/*
void TABLERO::DAR_VALOR_XMAX(float valor)
{
	XMAX = valor;
}

void TABLERO::DAR_VALOR_ZMAX(float valor)
{
	ZMAX = valor;
}

float TABLERO::MOSTRAR_XMAX(void)
{
	return XMAX;
}

float TABLERO::MOSTRAR_ZMAX(void)
{
	return ZMAX;
}
*/


