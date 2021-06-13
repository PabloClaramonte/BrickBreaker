#pragma once

#include <PuntosCartesianos.h>
#include <ObjetoMovil.h>
#include <ETSIDI.h>

using ETSIDI::SpriteSequence;

class ZOMBIE : public OBJETOMOVIL
{
private:
	int impactos;
	float radio;
	SpriteSequence sprite_zombie;

public:

	//ZOMBIE(); 

	ZOMBIE(float r=0.0f, float x = 0.0f, float z = 0.0f, float v = 0.0f, int im=0);
	~ZOMBIE();

	virtual void DIBUJA (void);
	virtual void MUEVE(float t);

	int getImpacto();

	PUNTOSCARTESIANOS getPos();


	friend class INTERACCIONES;
};

