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
	void SetPos(float ix, float iy);

	/*Habrá disparos de diferentes colores en función del arma:
	Pistola: Disparo único. Balas Negras
	Escopeta: Disparo 3 balas en 3 direcciones. Balas Rojas.
	Subfusil: Disparo en ráfaga. Balas Amarillas. */
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	//Posteriormente podemos usar sprites para los disparos, que es mejor opción.


	//Velocidad, posición, aceleración del disparo 
	PuntosCartesianos posicion;
	PuntosCartesianos velocidad;

	//PuntosCartesianos aceleracion; //si queremos que el disparo varíe su velocidad??

	void getDir(unsigned char key);
};

