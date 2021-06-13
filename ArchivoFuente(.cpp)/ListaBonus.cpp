#include "ListaBonus.h"


LISTABONUS::LISTABONUS()
{
    //Inicialización de la lista para que no contenga ninguna info al principio:
    NUMERO = 0;
    for (int i = 0; i < MAX_BONUS; i++)
        LISTA[i] = 0;
}

LISTABONUS::~LISTABONUS()
{
}

bool LISTABONUS::AGREGAR(BONUS* b)
{
    if (NUMERO < MAX_BONUS)
        LISTA[NUMERO++] = b; // último puesto sin rellenar
    else
        return false; // capacidad máxima alcanzada
    return true;
}

void LISTABONUS::DIBUJA()
{
    for (int i = 0; i < NUMERO; i++)
        LISTA[i]->DIBUJA();
}

void LISTABONUS::DESTRUIRBONUS()
{
    for (int i = 0; i < NUMERO; i++) // destrucción de zombies
        delete LISTA[i];
    NUMERO = 0; // inicializa lista 

}

void LISTABONUS::ELIMINAR(int INDEX)
{
    if ((INDEX < 0) || (INDEX >= NUMERO))
        return;
    delete LISTA[INDEX];
    NUMERO--;
    for (int i = INDEX; i < NUMERO; i++)
        LISTA[i] = LISTA[i + 1];

}

void LISTABONUS::ELIMINAR(BONUS* b)
{
    for (int i = 0; i < NUMERO; i++)
        if (LISTA[i] == b)
        {
            ELIMINAR(i);
            return;
        }
}
BONUS* LISTABONUS::operator [](int i)
{
    if (i >= NUMERO)//si me paso, devuelvo la ultima
        i = NUMERO - 1;

    if (i < 0) //si el indice es negativo, devuelvo la primera 
        i = 0;
    return LISTA[i];
}
