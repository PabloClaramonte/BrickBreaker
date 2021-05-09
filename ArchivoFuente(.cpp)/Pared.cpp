#include "Pared.h"
#include<freeglut.h>

Pared::Pared()
{
	ROJO = 0;
	verde = 0;
	azul = 0;
	
}

Pared::~Pared()
{
}

void Pared::SetColor(unsigned char r, unsigned char v, unsigned char a)
{
	ROJO = r;
	verde = v;
	azul = a;
}

void Pared::setPos(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4)
{
	LIMITE1.X = x1;
	LIMITE1.Y = y1;
	LIMITE1.Z = z1;
	LIMITE2.X = x2;
	LIMITE2.Y = y2;
	LIMITE2.Z = z2;
	LIMITE3.X = x3;
	LIMITE3.Y = y3;
	LIMITE3.Z = z3;
	LIMITE4.X = x4;
	LIMITE4.Y = y4;
	LIMITE4.Z = z4;

}

void Pared::Dibuja()
{
	glDisable(GL_LIGHTING);
	glColor3ub(ROJO, verde, azul);
	glBegin(GL_POLYGON);
	glVertex3f(LIMITE1.X, LIMITE1.Y, LIMITE1.Z);
	glVertex3f(LIMITE2.X, LIMITE2.Y, LIMITE2.Z);
	glVertex3f(LIMITE3.X, LIMITE3.Y, LIMITE3.Z);
	glVertex3f(LIMITE4.X, LIMITE4.Y, LIMITE4.Z);
	glEnd();
	glEnable(GL_LIGHTING);
}
