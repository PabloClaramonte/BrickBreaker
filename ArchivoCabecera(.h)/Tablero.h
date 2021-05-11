#pragma once
#include <freeglut.h>

class TABLERO {

private:
	
	/*Los limites del mapa, el cual sera rectangular o cuadrado, estan limitados por un poligono el cual partira de
	  la coordenada (0,0,0) y estara siempre en el plano Y=0. Los limites tanto de las coordenadas X Y Z seran el 0 
	  y sus correspondientes coordenadas maximas.
	*/

	float XMAX;//Este atributo hace referencia a la corrdenada X maxima que tendra el mapa.
	float ZMAX;//Este atributo hace referencia a la coordenada Z maxima que tendra el mapa. 


public:

	//Constructor por defecto.
	TABLERO() 
	{
		XMAX = 0.0f;
		ZMAX = 0.0f;
	};

	//Destructor por defecto.
	~TABLERO()
	{
	
	};

	//Metodo encargado de dibujar el TABLERO.
	void DIBUJA(void);

	//Metodo encargado de dar valor al atributo XMAX. 
	void DAR_VALOR_XMAX(float valor);

	//Metodo encargado de dar valor al atributo ZMAX. 
	void DAR_VALOR_ZMAX(float valor);

	//Metodo encargado de devolver el atributo XMAX.
	float MOSTRAR_XMAX(void);

	//Metodo encargado de devolver el atributo ZMAX. 
	float MOSTRAR_ZMAX(void);


	friend class INTERACCIONES;
	friend class MUNDO;
};
