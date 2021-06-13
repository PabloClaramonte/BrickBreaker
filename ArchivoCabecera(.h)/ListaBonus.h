#pragma once

#include "Bonus.h"
#include "Interaccion.h"
#define MAX_BONUS 3

class LISTABONUS
{
private:
    BONUS* LISTA[MAX_BONUS];
    int NUMERO;

public:
    LISTABONUS();
    virtual ~LISTABONUS();
    bool AGREGAR(BONUS* b);
    void DESTRUIRBONUS();
    void DIBUJA();

    void ELIMINAR(BONUS* b);
    void ELIMINAR(int index);

    BONUS* operator[](int i);

    friend class INTERACCIONES;
};

