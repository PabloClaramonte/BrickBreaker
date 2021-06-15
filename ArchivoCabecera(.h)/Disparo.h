#pragma once

#include <PuntosCartesianos.h>
#include <freeglut.h>
#include <ObjetoMovil.h>

using ETSIDI::SpriteSequence;

class DISPARO : public OBJETOMOVIL
{
	SpriteSequence sprite;
public:

	DISPARO(float x = 0.0f, float z = 0.0f, float vx = 0.0f, float vz = 0.0f);
	virtual ~DISPARO();

	virtual void DIBUJA(void);
	void MUEVE(float t);
	void SetVel(float vx, float vz);
	void setPos(float x, float z);

	friend class MUNDO;
	friend class INTERACCIONES;
};

