#include "PuntosCartesianos.h"
#include "freeglut.h"

class Pared
{
public:
	Pared();
	virtual ~Pared();

	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;

	PuntosCartesianos limite1;
	PuntosCartesianos limite2;
	PuntosCartesianos limite3;
	PuntosCartesianos limite4;

	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void setPos(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4);
	void Dibuja();
};

