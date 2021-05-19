#include <Columna.h>


COLUMNA::COLUMNA()
{
	TAMANOCOLUMNA = 4;
}

COLUMNA::~COLUMNA()
{
}

void COLUMNA::DIBUJAR(void)
{
	glPushMatrix();
	glColor3f(0.0f, 1.0f, 1.0f);
	glTranslatef(POSICION.X, POSICION.Y, POSICION.Z);
	glutSolidCube(TAMANOCOLUMNA);
	glTranslatef(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

/*
float COLUMNA::MOSTRAR_LIMITE_MAXIMO_EJE_X(int numerocolum)
{
	return (OBTENERVALOR_X() + (TAMAÑOCOLUMNA / 2));
}

float COLUMNA::MOSTRAR_LIMITE_MINIMO_EJE_X(int numerocolum)
{
	return (OBTENERVALOR_X() - (TAMAÑOCOLUMNA / 2));
}

float COLUMNA::MOSTRAR_LIMITE_MAXIMO_EJE_Z(int numerocolum)
{
	return (OBTENERVALOR_Z() + (TAMAÑOCOLUMNA / 2));
}

float COLUMNA::MOSTRAR_LIMITE_MINIMO_EJE_Z(int numerocolum)
{
	return (OBTENERVALOR_Z() - (TAMAÑOCOLUMNA / 2));
}
*/