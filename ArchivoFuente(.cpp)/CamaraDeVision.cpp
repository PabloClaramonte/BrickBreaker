//Zona de #includes.
#include"CamaraDeVision.h"
//Fin zona #includes.

CamaraDeVision::CamaraDeVision() //Cuerpo del Constructor por defecto.
{
	//Vlores iniciales donde mira la camara.
	LookAt_x = 0.0;
	LookAt_y = 0.0;
	LookAt_z = 0.0;

	//Valores iniciales donde esta situada la camara.
	Position_x = 0.0;
	Position_y = 0.0; 
	Position_z = 0.0;
	
	//Los valores del autogiro una vez se contruya el objeto nunca se modificaran.
	Swap_x = 0.0,
	Swap_y = 1.0;
    Swap_z = 0.0;

}

CamaraDeVision::~CamaraDeVision() //Cuerpo del Destrcutorpor defecto.
{

}

 void CamaraDeVision::SeguimientoPersonaje(float x,float y,float z)
{
	 //La camara apunta siempre al personaje.
	 LookAt_x = x; 
	 LookAt_y = y;
	 LookAt_z = z;

	 //La camara siempre se situa a la misma distancia del personaje, para mantener la misma perspectiva.
	 Position_x = x;
	 Position_y = (y + 40);
	 Position_z = (z + 40);

	 /* Los arguementos de la funcion son las coordenadas x,y,z del personaje que vamos a crear. Por lo que cuando 
	    llamemos al metodo en el codigo principal debemos asegurarnos que utilizamos los metodos de la clase Jugador.h
		correspondientes para que devuelvan los valores antes especificados.

		La distancia de la camara al personaje ( es decir el +20 y el +40 se puede cambiar como queramos para que la 
		camara tenga la perspectivas que deseemos.
	 */
}
