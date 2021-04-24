//Zona de #includes.
#include"CamaraDeVision.h"
//Fin zona #includes.

CamaraDeVision::CamaraDeVision()
{
	
	velocidad.x =0.0f;
	velocidad.y =0.0f;
	velocidad.z = 0.0f;
	vista.x = heroe.posicion.x;
	vista.y = heroe.posicion.y;
	vista.z = heroe.posicion.z;

	posicion.x = heroe.posicion.x - 40;
	posicion.y = heroe.posicion.y + 40;
	posicion.z = heroe.posicion.z;
	giro.x = 0.0f;
	giro.y = 1.0f;
	giro.z = 0.0f;
}

CamaraDeVision::~CamaraDeVision() //Cuerpo del Destrcutorpor defecto.
{

}
void CamaraDeVision::SetVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.z = vy;
}
void CamaraDeVision::Pos(Jugador j)
{
	posicion = j.getPos();	
	vista = j.getPos();

}
 void CamaraDeVision::Inicializa()
{ 
	 /*vista.x = heroe.posicion.x;
	 vista.y = heroe.posicion.y;
	 vista.z = heroe.posicion.z;*/

	 //La posición de la cámara es la misma que la del personaje, con cierta distancia
	 posicion.x = heroe.posicion.x - 40; 
	 posicion.y = heroe.posicion.y + 40;
	 posicion.z = heroe.posicion.z;
} 
 void CamaraDeVision::Mueve(float t)
 {
	posicion.x = posicion.x + velocidad.x * t;
	posicion.z = posicion.z + velocidad.z * t;
	vista.x = vista.x + velocidad.x * t;
	vista.z =vista.z + velocidad.z * t;
 }
 void CamaraDeVision::tecla(unsigned char key,float t)
 {
	 switch (key)
	 {
		case 'w':
		 {
			 SetVel(10.0, 0.0);
			break;
		 }
		 case 's':
		 {
			 SetVel(-10.0, 0.0);	 

			 break;
		 }
		 case 'a':
		{
			 SetVel(0.0, -10.0);
			 break;
		}
		 case 'd':
		 {
			 SetVel(0.0, 10.0);

			 break;
		 }
		 case ' ':
			 SetVel(0.0, 0.0);
			 break;
	 }
 }

