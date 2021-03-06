#include "ListaZombies.h"

LISTAZOMBIES::LISTAZOMBIES()
{
    //Inicializaci�n de la lista para que no contenga ninguna info al principio:
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
        LISTA[NUMERO++] = z; // �ltimo puesto sin rellenar
    else
        return false; // capacidad m�xima alcanzada
    return true;
}

void LISTAZOMBIES::MUEVE()
{
    for (int i = 0; i < NUMERO; i++)
        LISTA[i]->MUEVE(0.0f);    //Se usa el operador -> porque se accede a direcciones
}

void LISTAZOMBIES::DIBUJA()
{
    for (int i = 0; i < NUMERO; i++)
        LISTA[i]->DIBUJA();
}

void LISTAZOMBIES::DESTRUYECONTENIDO()
{
    for (int i = 0; i < NUMERO; i++) // destrucci�n de zombies
        delete LISTA[i];
    NUMERO = 0; // inicializa lista 

}

void LISTAZOMBIES::ELIMINAR(int INDEX)
{
    if ((INDEX < 0) || (INDEX >= NUMERO))
        return;
    delete LISTA[INDEX];
    NUMERO--;
    for (int i = INDEX; i < NUMERO; i++)
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

void LISTAZOMBIES::CHOQUE_ENTRE_ZOMBIES()
{
    for (int i = 0; i < NUMERO - 1; i++)
        for (int j = i + 1; j < NUMERO; j++)
            INTERACCIONES::COLISION(*(LISTA[i]), *(LISTA[j]),HEROE);
}



ZOMBIE* LISTAZOMBIES::COLISION(JUGADOR HEROE)
{
    for (int i = 0; i < NUMERO; i++)
    {
        if (INTERACCIONES::COLISION(HEROE, *(LISTA[i])))
            return LISTA[i];
    }

    return 0; // No hay colisi�n
}

int LISTAZOMBIES::getNumero()
{
    return NUMERO;
}

ZOMBIE* LISTAZOMBIES::operator [](int i)
{
    if (i >= NUMERO)//si me paso, devuelvo la ultima
        i = NUMERO - 1;

    if (i < 0) //si el indice es negativo, devuelvo la primera 
        i = 0;
    return LISTA[i];
}
