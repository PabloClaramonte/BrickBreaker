#pragma once

class PUNTOSCARTESIANOS
{
public:
	//Son las tres variables sobre las cuales dependera todo el resto de los elementos, para poderlos situar en el mundo.
	float X, Y, Z;

	//Constructor por defecto.
	PUNTOSCARTESIANOS(float x = 0.0f, float  y = 0.0f, float z = 0.0f);

	//Destructor por defecto.
	~PUNTOSCARTESIANOS();

	float Modulo();
	float argumento(); // (3) argumento del vector
	PUNTOSCARTESIANOS Unitario(); // (4) devuelve un vector unitario
	PUNTOSCARTESIANOS operator - (PUNTOSCARTESIANOS&); // (5) resta de vectores
	PUNTOSCARTESIANOS operator + (PUNTOSCARTESIANOS&); // (6) suma de vectores
	float operator *(PUNTOSCARTESIANOS&); // (7) producto escalar
	PUNTOSCARTESIANOS operator *(float); // (8) producto por un escalar
};
