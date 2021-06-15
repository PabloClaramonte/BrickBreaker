#include "ListaColumnas.h"

LISTACOLUMNAS::LISTACOLUMNAS()
{
    //Inicialización de la lista para que no contenga ninguna info al principio:
    NUMERO = 0;
    for (int i = 0; i < MAX_COLUMNAS; i++)
        LISTA[i] = 0;
}

LISTACOLUMNAS::~LISTACOLUMNAS()
{
}

bool LISTACOLUMNAS::AGREGAR(COLUMNA* c)
{
    if (NUMERO < MAX_COLUMNAS)
        LISTA[NUMERO++] = c; // último puesto sin rellenar
    else
        return false; // capacidad máxima alcanzada
    return true;
}

void LISTACOLUMNAS::DIBUJA(void)
{
    for (int i = 0; i < NUMERO; i++)
        LISTA[i]->DIBUJA();
}

void LISTACOLUMNAS::DESTRUYECONTENIDO()
{
    for (int i = 0; i < NUMERO; i++) // destrucción de zombies
        delete LISTA[i];
    NUMERO = 0; // inicializa lista 
}

void LISTACOLUMNAS::ELIMINAR(int INDEX)
{
    if ((INDEX < 0) || (INDEX >= NUMERO))
        return;
    delete LISTA[INDEX];
    NUMERO--;
    for (int i = INDEX; i < INDEX; i++)
        LISTA[i] = LISTA[i + 1];
}

void LISTACOLUMNAS::ELIMINAR(COLUMNA* c)
{
    for (int i = 0; i < NUMERO; i++)
        if (LISTA[i] == c)
        {
            ELIMINAR(i);
            return;
        }
}

bool LISTACOLUMNAS::CHOQUE_JUGADOR(JUGADOR HEROE)
{
    for (int i = 0; i < NUMERO; i++)
        if (INTERACCIONES::COLISION(HEROE, *(LISTA[i])))
            return 1; // si hay choque
    return 0; //no hay choque
}

void LISTACOLUMNAS::CHOQUE_DISPARO(DISPARO BALA)
{
    for (int i = 0; i < NUMERO; i++)
        INTERACCIONES::COLISION(BALA, *(LISTA[i]));
}

void LISTACOLUMNAS::CHOQUE_ZOMBIE(ZOMBIE MALO)
{
    for (int i = 0; i < NUMERO; i++)
        INTERACCIONES::COLISION(MALO, *(LISTA[i]));
}

int LISTACOLUMNAS::getNumero()
{
    return NUMERO;
}

COLUMNA* LISTACOLUMNAS::operator [](int i)
{
    if (i >= NUMERO)//si me paso, devuelvo la ultima
        i = NUMERO - 1;

    if (i < 0) //si el indice es negativo, devuelvo la primera 
        i = 0;
    return LISTA[i];
}
