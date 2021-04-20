//Zona de #includes.

//Declaracion de la clase.
class CamaraDeVision  {

private:

	float LookAt_x, LookAt_y, LookAt_z; //Hacia donde mira la camara.
	float Position_x, Position_y, Position_z; //Donde esta situada la camara.
	float Swap_x, Swap_y, Swap_z; //Autogiro de la camara.

public:

	CamaraDeVision(); //Declaracion del Constructor por defecto.
	~CamaraDeVision(); //Declaracion del Destrcutor por defecto.

	//Metodo para mover la camara con el personaje.
	void SeguimientoPersonaje(float x, float y, float z);

	//Meotodos para coger los valores donde apunta la camara.
	float A_x(void) { return LookAt_x; }
	float A_y(void) { return LookAt_y; }
	float A_z(void) { return LookAt_z; }

	//Metodos para coger los valores donde se posiciona la camara.
	float P_x(void) { return Position_x; }
	float P_y(void) { return Position_y; }
	float P_z(void) { return Position_z; }

	//Metodos para coger los valor de autogiro. 
	float S_x(void) { return Swap_x; }
	float S_y(void) { return Swap_y; }
	float S_z(void) { return Swap_z; }


};
