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

	/*Habr� disparos de diferentes colores en funci�n del arma:
	Pistola: Disparo �nico. Balas Negras
	Escopeta: Disparo 3 balas en 3 direcciones. Balas Rojas.
	Subfusil: Disparo en r�faga. Balas Amarillas. */
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	//Posteriormente podemos usar sprites para los disparos, que es mejor opci�n.


	//Velocidad, posici�n, aceleraci�n del disparo 
	PuntosCartesianos posicion;
	PuntosCartesianos velocidad;

	//PuntosCartesianos aceleracion; //si queremos que el disparo var�e su velocidad??

	void getDir(unsigned char key);
};

