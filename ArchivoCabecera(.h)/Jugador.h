//Zona de #includes.
#pragma once
#include "PuntosCartesianos.h"
#include "freeglut.h"

#include "ETSIDI.h"
using ETSIDI::SpriteSequence;
//Fin zona #includes.

/*Esta clase es heredada de la clase PuntosCartesianos, de esta forma tenemos los atributos x,y,z heredados y privados
  por lo que solo podemos acceder a ellos con los metodos publicos especificados en la clase antes mencionada.
*/
class JUGADOR 
{
private:
	SpriteSequence sprite{ "imagenes/pangPlayer.png", 5 };
	float VELOCIDAD;//Atributo encargado de saber en cuantas unidades se incrementa la posicion del jugador cada ciclo de 25ms.
	char WSAD;//Atributo encargado de conocer la direccion en la cual se mueve el JUGADOR o si comienza a disparar.
	char PREWSAD;//Atributo encargado de conocer la ultima direccion del JUGADOR, antes de pararse para disparar.
	PUNTOSCARTESIANOS POSICION;//Atributo encargado de conocer la posicion del jugador en el mapa.

public:
	//Constructor con argumentos (sustituye al costructor sin argumentos para poder inicializar en menos líneas):
	JUGADOR(float X = 0.0f, float Y = 0.0f, float Z = 0.0f, float VEL = 0.0f);

	//Destrcutor por defecto.
	~JUGADOR();
	
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
