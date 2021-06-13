#pragma once
#include "Zombie.h"

#include "freeglut.h"
#include <ETSIDI.h>

using ETSIDI::SpriteSequence;

class SUPERZOMBIE :public ZOMBIE
{
private:
	float radio;
	int impactos;
	SpriteSequence sprite_superzombie;
public:

	SUPERZOMBIE(float r, float x, float z, float v, int im): ZOMBIE(r,x,z,v),sprite_superzombie("imagenes/SuperZombie.png", 4, 2, 100)
	{
		sprite_superzombie.setCenter(3.5, 0);
		sprite_superzombie.setSize(10, 10);
		impactos = 0;
		//POSICION.X = x;
		//POSICION.Z = z;
		//impactos = im;
		//velocidad = v;
		//radio = r;
	}
	~SUPERZOMBIE() {};
	void DIBUJA();
	void MUEVE(float t);

};

