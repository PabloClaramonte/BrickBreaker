#pragma once
#include "Zombie.h"

#include "freeglut.h"

class SUPERZOMBIE :public ZOMBIE
{
private:
	float color;
	float radio;
public:
	SUPERZOMBIE(float x, float z, float v, float c, float r) :ZOMBIE(x, z, v)
	{
		color = c;
		radio = r;
	}
	~SUPERZOMBIE() {};
	void DIBUJA();

};

