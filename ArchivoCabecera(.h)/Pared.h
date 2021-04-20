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

	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void setPos(float x1, float y1, float x2, float y2);
	void Dibuja();
};

