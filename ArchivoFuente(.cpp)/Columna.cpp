#include <Columna.h>

COLUMNA::COLUMNA(float x, float z, int t)
{
	POSICION.X = x;
	POSICION.Z = z;
	TAMANOCOLUMNA = t;
}

COLUMNA::~COLUMNA()
{
}

void COLUMNA::DIBUJA(void)
{
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(POSICION.X, POSICION.Y, POSICION.Z);
	glutSolidCube(TAMANOCOLUMNA);
	glTranslatef(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}