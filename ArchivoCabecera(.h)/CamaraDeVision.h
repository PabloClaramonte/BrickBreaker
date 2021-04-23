//Zona de #includes.
#include "Jugador.h"
#include "PuntosCartesianos.h"

//Declaracion de la clase.

class CamaraDeVision  {

public:
	CamaraDeVision();//constructor por defecto

	~CamaraDeVision(); //Declaracion del Destrcutor por defecto.

	PuntosCartesianos posicion;
	PuntosCartesianos vista;
	PuntosCartesianos giro;

	PuntosCartesianos velocidad;

	Jugador heroe;

	
	

	//Metodo para mover la camara con el personaje.
	void SetVel(float vx, float vz);
	void Pos(Jugador j);
	void tecla(unsigned char key, float t);
	void Inicializa();
	void Mueve(float t);

};
