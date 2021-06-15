#pragma once
#include"Disparo.h"
#include"Tablero.h"
#include"Interaccion.h"

#define MAX_DISPAROS 20

class LISTADISPAROS
{

private:
    DISPARO* LISTA[MAX_DISPAROS];
    int NUM;
public:
    LISTADISPAROS();
    virtual ~LISTADISPAROS();
    bool AGREGAR(DISPARO* d);
    void DESTRUIRDISPAROS();
    void MUEVE(float t);
    void DIBUJA();

    DISPARO* COLISION_MAPA(TABLERO t);

    void ELIMINAR(DISPARO* d);
    void ELIMINAR(int index);

    int getNumero();

    DISPARO* operator[](int i);

    friend class INTERACCIONES;
};

