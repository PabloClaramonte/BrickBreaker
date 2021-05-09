#pragma once
#define MAX_DISPAROS 100
#include "Disparo.h"
#include "Caja.h"

class ListaDisparos
{
public:
	ListaDisparos();
	virtual ~ListaDisparos();

	bool agregar(Disparo* d);
	void destruirContenido();
	void eliminar(Disparo* d);
	void eliminar(int index);
	void mueve(float t);
	void dibuja();

	void colision(Pared p);
	void colision(Caja c);

	int getNumero() { return numero; }
	Disparo* operator[] (int index);

private:
	Disparo* lista[MAX_DISPAROS];
	int numero;
};

