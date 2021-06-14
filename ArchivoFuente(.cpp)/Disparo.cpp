#include<Disparo.h>

DISPARO::DISPARO(float x, float z, float vx, float vz) : sprite("imagenes/bala.png", 1)
{
	POSICION.X = x;
	POSICION.Y = 4;
	POSICION.Z = z;
	VELOCIDAD.X = vx;
	VELOCIDAD.Z = vz;

	sprite.setCenter(1.5, 1.5);
	sprite.setSize(1, 1);
}

DISPARO::~DISPARO()
{
}

void DISPARO::DIBUJA(void)
{
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);
	glTranslatef(POSICION.X, POSICION.Y, POSICION.Z);
	//glutSolidSphere(0.5, 20, 20);
	glTranslatef(0, 0, 0);

	sprite.draw();

	glPopMatrix();
}


void DISPARO::SetVel(float vx, float vz)
{
	VELOCIDAD.X = vx;
	VELOCIDAD.Z = vz;
}
void DISPARO::MUEVE(float t)
{
	POSICION.X = POSICION.X + VELOCIDAD.X * t;
	POSICION.Z = POSICION.Z + VELOCIDAD.Z * t;
}


void DISPARO::setPos(float x, float z)
{
	POSICION.X = x;
	POSICION.Z = z;
}
