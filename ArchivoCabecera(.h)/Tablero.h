#pragma once
#include <freeglut.h>
#include "ETSIDI.h"

class TABLERO {

private:
	
	/*Los limites del mapa, el cual sera rectangular o cuadrado, estan limitados por un poligono el cual partira de
	  la coordenada (0,0,0) y estara siempre en el plano Y=0. Los limites tanto de las coordenadas X y Z seran el 0 
	  y sus correspondientes coordenadas maximas.
	*/

	float XMAX;//Este atributo hace referencia a la corrdenada X maxima que tendra el mapa.
	float ZMAX;//Este atributo hace referencia a la coordenada Z maxima que tendra el mapa. 


public:

	//Constructores
	TABLERO(float x = 0.0f, float z = 0.0f);

	//Destructor.
	~TABLERO() {};

	//Metodo encargado de dibujar el TABLERO.
	void DIBUJA(void);

	friend class INTERACCIONES;
	friend class MUNDO;
};
