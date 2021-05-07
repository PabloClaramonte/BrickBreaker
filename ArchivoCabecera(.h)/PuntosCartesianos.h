#pragma once

class PuntosCartesianos
{

public: 

	//Puntos Cartesianos X,Y,Z.
	float X, Y, Z;

	//Constructor por defecto.
	PuntosCartesianos() {};

	//Constructor por valor.
	PuntosCartesianos(float xi, float yi, float zi) { X = xi; Y = yi; Z = zi; }; 

	//Destructor
	~PuntosCartesianos() {}; 

};

