#include "Caja.h"

Caja::Caja()
{

    //Pared Izquierda
    Izquierda.SetColor(255, 0, 0); //Roja
    Izquierda.setPos(0, 0, 0, 0, 5, 0, 0, 5, 40, 0, 0, 40);
    //Pared Sur
    Sur.SetColor(0, 255, 255); //Turquesa
    Sur.setPos(0, 0, 40, 0, 5, 40, 40, 5, 40, 40, 0, 40);
    //Pared Norte
    Norte.SetColor(0, 255, 0); //Verde
    Norte.setPos(0, 0, 0, 0, 5, 0, 40, 5, 0, 40, 0, 0);
    //Pared Derecha
    Derecha.SetColor(0, 0, 255); //Azul
    Derecha.setPos(40, 0, 0, 40, 5, 0, 40, 5, 40, 40, 0, 40);
}

Caja::~Caja()
{
}

void Caja::Dibuja() {
    Derecha.Dibuja();
    Izquierda.Dibuja();
    Norte.Dibuja();
    Sur.Dibuja();

}