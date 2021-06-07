#include<Disparo.h>

DISPARO::DISPARO()
{

	POSICION.Y = 0.0;

	VELOCIDAD.Y = 0.0;
}

DISPARO::~DISPARO()
{
}

void DISPARO::DIBUJA(void)
{
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);
	glTranslatef(POSICION.X, POSICION.Y, POSICION.Z);
	glutSolidSphere(0.5, 20, 20);
	glTranslatef(0, 0, 0);
	glPopMatrix();
}


void DISPARO::SetVel(float vx, float vz)
{
	VELOCIDAD.X = vx;
	VELOCIDAD.Z = vz;
}
void DISPARO::Mueve(float t)
{
	POSICION.X = POSICION.X + VELOCIDAD.X * t;
	POSICION.Z = POSICION.Z + VELOCIDAD.Z * t;
}

DISPARO::DISPARO(float x , float z, float vx, float vz)
{
	POSICION.X = x;
	POSICION.Z = z;
	VELOCIDAD.X = vx;
	VELOCIDAD.Z = vz;
}
