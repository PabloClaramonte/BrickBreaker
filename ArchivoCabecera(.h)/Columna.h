#pragma once

#include <PuntosCartesianos.h>
#include <freeglut.h>

class COLUMNA
{
private:
	int TAMANOCOLUMNA;
	PUNTOSCARTESIANOS POSICION;
public:
	COLUMNA(); 
	COLUMNA(float x = 0.0f, float z = 0.0f, int t = 0);
	~COLUMNA();

	//Metodo encargado de dibujar la COLUMNA.
	void DIBUJA(void);

	friend class INTERACCIONES;
	friend class MUNDO;
};


