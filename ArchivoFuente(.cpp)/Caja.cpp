#include "Caja.h"

Caja::Caja()
{
    //Pared Sur 
    Sur.SetColor(255, 255, 0); //Amarillo
    Sur.setPos(-25.0f, 0, 25.0f, 0);
    //Pared Norte
    Norte.SetColor(0, 255, 0); //Verde
    Norte.setPos(-10.0f, 15.0f, 10.0f, 15.0f);
    //Pared Izquierda
    Izquierda.SetColor(0, 0, 255); //Azul
    Izquierda.setPos(-25.0f, 0, -25.0f, 5.0f);
    //Pared Derecha
    Derecha.SetColor(255, 0, 0); //Rojo
    Derecha.setPos(25.0f, 0, 25.0f, 5.0f);
}

Caja::~Caja()
{
}

void Caja::Dibuja() {
    Sur.Dibuja();
    Norte.Dibuja();
    Derecha.Dibuja();
    Izquierda.Dibuja();
}