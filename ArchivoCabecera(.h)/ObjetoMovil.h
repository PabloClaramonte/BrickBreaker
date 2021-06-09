#pragma once

//CLASE ABSTRACTA QUE ENGLOBA LAS FUNCIONES MUEVE Y DIBUJA DE LOS OBJETOS MÓVILES JUGADOR, ZOMBIE Y DISPARO.
class OBJETOMOVIL
{
protected:
	float VELOCIDAD; //Atributo encargado de saber en cuantas unidades se incrementa la posicion del objeto cada ciclo de 25ms.
public:
	OBJETOMOVIL() { VELOCIDAD = 0; }
	virtual ~OBJETOMOVIL() {}; //Importante que el destructor sea virtual

	//Funciones virtuales puras:
	virtual void MUEVE(float t) = 0;
	virtual void DIBUJA() = 0;
};

