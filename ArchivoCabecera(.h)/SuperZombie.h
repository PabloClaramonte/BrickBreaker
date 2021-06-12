#pragma once
#include "Zombie.h"

#include "freeglut.h"

class SUPERZOMBIE :public ZOMBIE
{
private:
	float color;
	float radio;
	int impactos;
public:
	SUPERZOMBIE(float r, float x, float z, float v, float c, int im) : ZOMBIE(r, x, z, v)
	{
		color = c;
		radio = r;
		impactos = im;
	};
	~SUPERZOMBIE() {};
	void DIBUJA();

};

