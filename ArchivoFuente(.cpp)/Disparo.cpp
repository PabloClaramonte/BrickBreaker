#include<Disparo.h>

//DISPARO::DISPARO() : sprite("imagenes/bala.png", 1)
//{
//	
//
//	POSICION.Y = 0.0;
//	VELOCIDAD.Y = 0.0;
//}

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

	if (VELOCIDAD.X != 0 && VELOCIDAD.Z == 0)
		sprite_horizontal.draw();

	if (VELOCIDAD.X == 0 && VELOCIDAD.Z != 0)
		sprite_vertical.draw();

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

DISPARO::DISPARO(float x , float z, float vx, float vz) : sprite_horizontal("imagenes/bala_h.png", 1), sprite_vertical("imagenes/bala_v.png", 1)
{
	POSICION.X = x;
	POSICION.Z = z;
	VELOCIDAD.X = vx;
	VELOCIDAD.Z = vz;

	sprite_horizontal.setCenter(1.5, 1.5);
	sprite_horizontal.setSize(2, 2);
	sprite_vertical.setCenter(1.5, 1.5);
	sprite_vertical.setSize(2, 2);

}
void DISPARO::setPos(float x, float z)
{
	POSICION.X = x;
	POSICION.Z = z;
}
