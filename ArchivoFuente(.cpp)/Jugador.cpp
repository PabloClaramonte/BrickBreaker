//Zona de #includes.
#include "Jugador.h"
//Fin zona de #includes.

//Cuerpo del constructor por defecto mas el cosntructor heredado de la clase PuntosCartesianos.
Jugador::Jugador():PuntosCartesianos()
{
}

//Cuerpo del destructor por defecto.
Jugador::~Jugador()
{
}

//Cuerpo del metodo Dibuja. !!!!Falta meter un ESPRITE que de momento el jugador es una esfera¡¡¡¡¡
void Jugador::Dibuja()
{
    glTranslatef(ValorEspacial_x(), ValorEspacial_y(), ValorEspacial_z());
    glColor3f(1.0f, 1.0f, 1.0f);
    glutSolidSphere(0.5, 20, 20);
    glTranslatef(0, 0, 0);
}

//Cuerpo del metodo que asigna nuevos valores a las coordenadas x,y,z heredadas de la clase PuntosCartesianos.
void Jugador::Mueve( unsigned char t)
{
    switch (t)
    {

    case 'w':
    {
        IncrementoValorEspacial_z(-0.5);
        break;
    }

    case 's':
    {
        IncrementoValorEspacial_z(+0.5);
        break;
    }

    case 'a':
    {
        IncrementoValorEspacial_x(-0.5);
        break;
    }

    case 'd': 
    {
        IncrementoValorEspacial_x(+0.5);
        break;
    }

    default:
        break;
    }

    /* Como los atributos heredados son privados solo podemos modificarlos con los metodos disponibles en la clase 
       PuntosCartesianos.
    */
}
