#include "Pared.h"
#include<freeglut.h>

Pared::Pared()
{
	rojo = 255;
	verde = 255;
	azul = 255;
	
	limite1.x = -10.0f;
	limite2.x = 10.0f;
	limite1.y = 0.0f;
	limite2.y = 15.0f;
	
}

Pared::~Pared()
{
}

void Pared::SetColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;
}

void Pared::setPos(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4)
{
	limite1.x = x1;
	limite1.y = y1;
	limite1.z = z1;
	limite2.x = x2;
	limite2.y = y2;
	limite2.z = z2;
	limite3.x = x3;
	limite3.y = y3;
	limite3.z = z3;
	limite4.x = x4;
	limite4.y = y4;
	limite4.z = z4;

	/*limitev1.vx = limite1.x;
	limitev1.vz = limite1.z;
	limitev2.vx = limite2.x;
	limitev2.vz = limite1.z;
	Suelo.setPos(-25.0f, 0, -10.0f, -25.0f, 0, 10.0f, 25.0f, 0, 10.0f, 25.0f, 0, -10.0f);*/
}
void Pared::Dibuja()
{
	glDisable(GL_LIGHTING);
	glColor3ub(rojo, verde, azul);
	glBegin(GL_POLYGON);
	glVertex3f(limite1.x, limite1.y, limite1.z);
	glVertex3f(limite2.x, limite2.y, limite2.z);
	glVertex3f(limite3.x, limite3.y, limite3.z);
	glVertex3f(limite4.x, limite4.y, limite4.z);

	glEnd();
	glEnable(GL_LIGHTING);
}
