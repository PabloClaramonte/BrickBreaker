#pragma once

class PUNTOSCARTESIANOS
{
public:

	//Son las tres variables sobre las cuales dependera todo el resto de los elementos, para poderlos situar en el mundo.
	float X, Y, Z;

	//Constructor por defecto.
	PUNTOSCARTESIANOS() { X = 0.0f; Y = 0.0f; Z = 0.0f; }

	//Destructor por defecto.
	~PUNTOSCARTESIANOS(){}

	//Getters (Se declaran en la cabecera para que sean Inline ya que se van a utilizar muchisimo).
	float OBTENERVALOR_X(void) { return X; }
	float OBTENERVALOR_Y(void) { return Y; }
	float OBTENERVALOR_Z(void) { return Z; }

	//Setters (Se delcaran en la cabecera para que sean Inline ya que se van a utilizar muchisimo).
	void DARVALOR_X(float valor) { X = valor; }
	void DARVALOR_Y(float valor) { Y = valor; }
	void DARVALOR_Z(float valor) { Z = valor; }

	//Incrementales y decrementales (Se delcaran en la cabecera para que sean Inline ya que se van a utilizar muchisimo).
	void INCREMENTAR_X(float valor) { X = X + valor; }
	void INCREMENTAR_Y(float valor) { Y = Y + valor; }
	void INCREMENTAR_Z(float valor) { Z = Z + valor; }
};
