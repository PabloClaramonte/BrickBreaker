#include "Caja.h"

Caja::Caja()
{
    //Suelo
    Suelo.SetColor(255, 255, 0); //Amarillo
    Suelo.setPos(-25.0f, 0, -10.0f, -25.0f, 0, 10.0f, 25.0f, 0, 10.0f, 25.0f, 0, -10.0f);
    //Pared Norte
    Norte.SetColor(255, 0, 0); //Roja
    Norte.setPos(-25.0f, 0, -10.0f, -25.0f, 10.0f, -10.0f, 25.0f, 10.0f, -10.0f, 25.0f, 0, -10.0f);
    //Pared Izquierda
    Izquierda.SetColor(0, 255, 0); //Verde
    Izquierda.setPos(-25.0f, 0, -10.0f, -25.0f, 10.0f, -10.0f, -25.0f, 10.0f, 10.0f, -25.0f, 0, 10.0f);
    //Pared Derecha
    Derecha.SetColor(0, 255, 0); //Verde
    Derecha.setPos(25.0f, 0, 10.0f, 25.0f, 10.0f, 10.0f, 25.0f, 10.0f, -10.0f, 25.0f, 0, -10.0f);
    //Pared Sur
    Sur.SetColor(0, 0, 255); //Azul
    Sur.setPos(-25.0f, 0, 10.0f, -25.0f, 10.0f, 10.0f, 25.0f, 10.f, 10.0f, 25.0f, 0, 10.0f);
}

Caja::~Caja()
{
}

void Caja::Dibuja() {
    Suelo.Dibuja();
    Sur.Dibuja();
    Norte.Dibuja();
    Derecha.Dibuja();
    Izquierda.Dibuja();

}