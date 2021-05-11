#include <Tablero.h>

void TABLERO::DIBUJA(void)
{
	
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(XMAX, 0, 0);
	glVertex3f(XMAX, 0, ZMAX);
	glVertex3f(0, 0, ZMAX);
	glVertex3f(0, 0, 0);
	glEnd();
	
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


