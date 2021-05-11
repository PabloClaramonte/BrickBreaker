#pragma once

#include <PuntosCartesianos.h>
#include <freeglut.h>


class COLUMNA 
{

private:

	int TAMANOCOLUMNA;

	PUNTOSCARTESIANOS POSICION;


public:

	//Constrcutor por defecto.
	COLUMNA() 
	{
		TAMANOCOLUMNA = 4;
	};

	//Destructor por defecto.
	~COLUMNA() 
	{

	};

	//Metodo encargado de dibujar la COLUMNA.
	void DIBUJAR(void);

	//Metodo encargado de devolver el valor maximo del eje X de cualquier columna. 
	float MOSTRAR_LIMITE_MAXIMO_EJE_X(int numerocolum);

	//Metodo encargado de devolver el valor minimo del eje X de cualquier columna.  
	float MOSTRAR_LIMITE_MINIMO_EJE_X(int numerocolum);

	//Metodo encargado de devolver el valor maximo del eje Z de cualquier columna. 
	float MOSTRAR_LIMITE_MAXIMO_EJE_Z(int numerocolum);

	//Metodo encargado de devolver el valor minimo del eje Z de cualquier columna. 
	float MOSTRAR_LIMITE_MINIMO_EJE_Z(int numerocolum);


	friend class INTERACCIONES;
	friend class MUNDO;
};


