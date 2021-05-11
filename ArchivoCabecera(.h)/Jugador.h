//Zona de #includes.
#pragma once
#include "PuntosCartesianos.h"
#include "freeglut.h"
//Fin zona #includes.

/*Esta clase es heredada de la clase PuntosCartesianos, de esta forma tenemos los atributos x,y,z heredados y privados
  por lo que solo podemos acceder a ellos con los metodos publicos especificados en la clase antes mencionada.
*/
class JUGADOR 
{

private:

	float VELOCIDAD;//Atributo encargado de saber en cuantas unidades se incrementa la posicion del jugador cada ciclo de 25ms.
	char WSAD;//Atributo encargado de conocer la direccion en la cual se mueve el JUGADOR o si comienza a disparar.
	char PREWSAD;//Atributo encargado de conocer la ultima direccion del JUGADOR, antes de pararse para disparar.
	PUNTOSCARTESIANOS POSICION;//Atributo encargado de conocer la posicion del jugador en el mapa.

public:

	//Constructor por defecto.
	JUGADOR()
	{
		POSICION.X = 0.0f;
		POSICION.Y = 0.0f;
		POSICION.Z = 0.0f;
		WSAD = NULL;
		PREWSAD = NULL;
	}; 

	//Destrcutor por defecto.
	~JUGADOR() {}
	
	//Metodo encargado del dibujado del personaje.
	void DIBUJA(void);

	//Metodo encargado del movimiento el personaje. 
	void MUEVE(void);

	//Metodo para poder modificar  el atributo WSDA.
	void MODIFICAR_WSDA(char tecla); 

	//Metodo para poder modificar el atributo PREWSDA.
	void MODIFICAR_PREWSDA(char tecla);

	//Metodo encargado de devolver el atributo WSDA.
	char MOSTRAR_WSDA(void); 

	//Metodo encargado de devolver el atributo PREWSDA.
	char MOSTRAR_PREWSDA(void); 


	friend class INTERACCIONES;
	friend class MUNDO;

};
