#include "Caja.h"

Caja::Caja()
{
    //Suelo
    Suelo.SetColor(255, 255, 0); //Amarillo
    Suelo.setPos(-25.0f, 0, -25.0f, -25.0f, 0, 25.0f, 25.0f, 0, 25.0f, 25.0f, 0, -25.0f);
    //Pared Izquierda
    Izquierda.SetColor(255, 0, 0); //Roja
    Izquierda.setPos(-25.0f, 0, -25.0f, -25.0f, 5.0f, -25.0f, 25.0f, 5.0f, -25.0f, 25.0f, 0, -25.0f);
    //Pared Sur
    Sur.SetColor(0, 255, 255); //Turquesa
    Sur.setPos(-25.0f, 0, -25.0f, -25.0f, 5.0f, -25.0f, -25.0f, 5.0f, 25.0f, -25.0f, 0, 25.0f);
    //Pared Norte
    Norte.SetColor(0, 255, 0); //Verde
    Norte.setPos(25.0f, 0.0f, 25.0f, 25.0f, 5.0f, 25.0f, 25.0f, 5.0f, -25.0f, 25.0f, 0, -25.0f);
    //Pared Derecha
    Derecha.SetColor(0, 0, 255); //Azul
    Derecha.setPos(-25.0f, 0, 25.0f, -25.0f, 5.0f, 25.0f, 25.0f, 5.0f, 25.0f, 25.0f, 0, 25.0f);
}

Caja::~Caja()
{
}

void Caja::Dibuja() {
    Suelo.Dibuja();
    Derecha.Dibuja();
    Izquierda.Dibuja();
    Norte.Dibuja();
    Sur.Dibuja();

}