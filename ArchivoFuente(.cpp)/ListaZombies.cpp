#include "ListaZombies.h"
//#include "..\ArchivoCabecera(.h)\ListaZombies.h"

LISTAZOMBIES::LISTAZOMBIES()
{
    //Inicialización de la lista para que no contenga ninguna info al principio:
    NUMERO = 0;
    for (int i = 0; i < MAX_ZOMBIES; i++)
        LISTA[i] = 0;
}

LISTAZOMBIES::~LISTAZOMBIES()
{
}

bool LISTAZOMBIES::AGREGAR(ZOMBIE* z)
{
    if (NUMERO < MAX_ZOMBIES)
        LISTA[NUMERO++] = z; // último puesto sin rellenar
    else
        return false; // capacidad máxima alcanzada
    return true;
}

void LISTAZOMBIES::MUEVE()
{
    for (int i = 0; i < NUMERO; i++)
        LISTA[i]->MUEVE();    //Se usa el operador -> porque se accede a direcciones
}

void LISTAZOMBIES::DIBUJA()
{
    for (int i = 0; i < NUMERO; i++)
        LISTA[i]->DIBUJA();
}

void LISTAZOMBIES::DESTRUYECONTENIDO()
{
    for (int i = 0; i < NUMERO; i++) // destrucción de zombies
        delete LISTA[i];
    NUMERO = 0; // inicializa lista 

}

void LISTAZOMBIES::ELIMINAR(int INDEX)
{
    if ((INDEX < 0) || (INDEX >= NUMERO))
        return;
    delete LISTA[INDEX];
    NUMERO--;
    for (int i = INDEX; i < INDEX; i++)
        LISTA[i] = LISTA[i + 1];
}

void LISTAZOMBIES::ELIMINAR(ZOMBIE* Z)
{
    for (int i = 0; i < NUMERO; i++)
        if (LISTA[i] == Z)
        {
            ELIMINAR(i);
            return;
        }
}

void LISTAZOMBIES::SIGUE_A_JUGADOR(JUGADOR HEROE)
{
    for (int i = 0; i < NUMERO; i++)
        INTERACCIONES::INTELIGENCIA_ARTIFICIAL_ZOMBIE(HEROE, *(LISTA[i]));
}

void LISTAZOMBIES::CHOCA_COLUMNA(COLUMNA COL)
{
    for (int i = 0; i < NUMERO; i++)
        INTERACCIONES::INTERACCION_ZOMBIE_COLUMNA(*(LISTA[i]), COL);
}

void LISTAZOMBIES::MATA_DISPARO(DISPARO BALA)
{
    for (int i = 0; i < NUMERO; i++)
        INTERACCIONES::INTERACCION_BALA_ZOMBIE(BALA, *(LISTA[i]));
}

void LISTAZOMBIES::CHOQUE_ENTRE_ZOMBIES()
{
    for (int i = 0; i < NUMERO - 1; i++)
        for (int j = i + 1; j < NUMERO; j++)
            INTERACCIONES::CHOQUE_ENTRE_ZOMBIES(*(LISTA[i]), *(LISTA[j]));
}


//Gestor del impacto zombie con jugador:
void LISTAZOMBIES::COLISION(JUGADOR HEROE)
{
    for (int i = 0; i < NUMERO - 1; i++)
        for (int j = i + 1; j < NUMERO; j++)
            INTERACCIONES::INTERACCION_JUGADOR_ZOMBIE(HEROE, *(LISTA[i]));
}
