#include "PuntosCartesianos.h"
#include "freeglut.h"

class Disparo
{
public:
	Disparo();
	virtual ~Disparo();

	float radio;

	void Mueve(float t);
	void Dibuja();
	void SetPos(float ix, float iz);
	void SetVel(float vx, float vz);

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

	//Funci�n que asigna una velocidad y direcci�n al disparo.
	void tecla(unsigned char key);
};

