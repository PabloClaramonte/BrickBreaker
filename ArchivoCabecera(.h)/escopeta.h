#pragma once
#include "Disparo.h"
#include "freeglut.h"

class ESCOPETA :public DISPARO
{
private:
	float color;
	float radio;
public:
	
	ESCOPETA(float x, float z, float vx, float vz, float c, float r) :DISPARO(x, z, vx, vz)
	{ 
		color = c;
		radio = r;
	};
	virtual ~ESCOPETA() {};
	void DIBUJA();

};

