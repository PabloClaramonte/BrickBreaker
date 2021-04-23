//Zona de #includes.
#include "PuntosCartesianos.h"

PuntosCartesianos::PuntosCartesianos()//Cuerpo del Constructor por defecto.
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

PuntosCartesianos::PuntosCartesianos(float xi, float yi, float zi)//contructor simple
{
	x = xi;
	y = yi;
	z = zi;
}


PuntosCartesianos::~PuntosCartesianos()//Cuerpo del Destrcutor por defecto.
{

}