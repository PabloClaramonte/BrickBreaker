#include "PuntosCartesianos.h"
#include "Jugador.h"
#include <math.h>
#include "freeglut.h"

class Disparo
{
public:
	Disparo();
	virtual ~Disparo();

	float radio;
	float angulo;
	float v_ang; //velocidad angular de giro de la direccion de tiro
	float dist;
	void Mueve(float t);
	void direccion(float t);
	void Dibuja();
	void SetPos(float ix, float iz);
	void SetVel(float vx, float vz);
	void SetVelAng(float w);

	/*Habrá disparos de diferentes SPRITES en función del arma:
	Pistola: Disparo único. 
	Escopeta: Disparo 3 balas en 3 direcciones.
	Subfusil (UZI): Disparo en ráfaga. */
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;

	//Velocidad y posición del disparo 
	PuntosCartesianos posicion;
	PuntosCartesianos velocidad;
	Jugador j;


	//Función que asigna una velocidad y dirección al disparo.
	void tecla(unsigned char key);
};

