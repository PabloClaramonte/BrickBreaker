#pragma once
#include "Disparo.h"
#include "freeglut.h"

using ETSIDI::SpriteSequence;

class ESCOPETA :public DISPARO
{
	SpriteSequence sprite;
private:
	float color;
	float radio;
public:
	
	ESCOPETA(float x, float z, float vx, float vz, float c, float r) :DISPARO(x, z, vx, vz), sprite("imagenes/escopeta.png", 1)
	{ 
		color = c;
		radio = r;

		POSICION.Y = 5.0f;

		sprite.setCenter(1.5, 1.5);
		sprite.setSize(1, 1);
	};

	virtual ~ESCOPETA() {};
	void DIBUJA();
};

