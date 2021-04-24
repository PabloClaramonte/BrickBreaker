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

	/*Habr� disparos de diferentes SPRITES en funci�n del arma:
	Pistola: Disparo �nico. 
	Escopeta: Disparo 3 balas en 3 direcciones.
	Subfusil (UZI): Disparo en r�faga. */
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;

	//Velocidad y posici�n del disparo 
	PuntosCartesianos posicion;
	PuntosCartesianos velocidad;
	Jugador j;


	//Funci�n que asigna una velocidad y direcci�n al disparo.
	void tecla(unsigned char key);
};

