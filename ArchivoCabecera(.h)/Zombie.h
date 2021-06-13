#pragma once

#include <PuntosCartesianos.h>
#include <ObjetoMovil.h>

class ZOMBIE : public OBJETOMOVIL
{
private:
	int impactos;
	float radio;
public:

	ZOMBIE(); //Constructor sin argumentos
	ZOMBIE(float r=0.0f, float x = 0.0f, float z = 0.0f, float v = 0.0f, int im=0);
	~ZOMBIE();

	virtual void DIBUJA (void);
	void MUEVE(float t);

	int getImpacto();

	PUNTOSCARTESIANOS getPos();


	friend class INTERACCIONES;
};

