#pragma once

class PuntosCartesianos
{

public: 

	//Son las tres variables sobre las cuales dependera todo el resto de los elementos, para poderlos situar en el mundo.
	float x, y, z;

	PuntosCartesianos();
	PuntosCartesianos(float xi, float yi,float zi); // Declaracion del Constructor.
	~PuntosCartesianos(); //Declaracion del Destructor.

};

