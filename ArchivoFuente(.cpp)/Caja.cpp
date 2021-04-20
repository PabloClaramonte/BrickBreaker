#include "Caja.h"

Caja::Caja()
{
    Sur.SetColor(0, 100, 0);
    Sur.setPos(-10.0f, 0, 10.0f, 0);
    Norte.SetColor(0, 100, 0);
    Norte.setPos(-10.0f, 15.0f, 10.0f, 15.0f);

    Derecha.SetColor(0, 150, 0);
    Derecha.setPos(-10.0f, 0, -10.0f, 15.0f);
    Izquierda.SetColor(0, 150, 0);
    Izquierda.setPos(10.0f, 0, 10.0f, 15.0f);
}

Caja::~Caja()
{
}

void Caja::Dibuja() {
    Sur.Dibuja();
    Norte.Dibuja();
    Izquierda.Dibuja();
    Derecha.Dibuja();
}