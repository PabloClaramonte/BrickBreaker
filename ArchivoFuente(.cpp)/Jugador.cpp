//Zona de #includes.
#include "Jugador.h"

//Fin zona de #includes.

//Cuerpo del constructor por defecto mas el cosntructor heredado de la clase PuntosCartesianos.
Jugador::Jugador()//:PuntosCartesianos()
{
    rojo = verde = azul = 0;
    posicion.x = posicion.y = posicion.z = 0.0f;
    velocidad.x = velocidad.y = velocidad.z = 0.0f;
    
}

//Cuerpo del destructor por defecto.
Jugador::~Jugador()
{
}

//Cuerpo del metodo Dibuja. !!!!Falta meter un ESPRITE que de momento el jugador es una esfera¡¡¡¡¡
void Jugador::Dibuja()
{
   // glTranslatef(ValorEspacial_x(), ValorEspacial_y(), ValorEspacial_z());
    glTranslatef(posicion.x, posicion.y, posicion.z);
    glColor3f(1.0f, 0.0f, 1.0f);
    glutSolidSphere(2, 20, 20);
    glTranslatef(0, 0, 0);
}

void Jugador::SetVel(float vx, float vy)
{
    velocidad.x = vx;
    velocidad.z = vy;
}
void Jugador::Mueve(float t)
{
    posicion.x = posicion.x + velocidad.x *t;
    posicion.z = posicion.z + velocidad.z * t;
}
PuntosCartesianos Jugador::getPos()
{
    PuntosCartesianos p;
    p.x = posicion.x;
    p.y = posicion.y;
    p.z = posicion.z;
    return p;
}

//Cuerpo del metodo que asigna nuevos valores a las coordenadas x,y,z heredadas de la clase PuntosCartesianos.
void Jugador::tecla(unsigned char key)
{
    switch (key)
    {
    case 'w':
    {
        SetVel(5.0,0.0);
        break;
    }
    case 's':
    {
        SetVel(-5.0, 0.0);
        break;
    }
    case 'a':
    {
        SetVel(0.0, -5.0);
        break;
    }
    case 'd': 
    {
        SetVel(0.0, 5.0);;
        break;
    }
    case 'NULL':
        SetVel(0.0, 0.0);
        break;
    }

   
}
