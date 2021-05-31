#pragma once
#include "Mundo.h"

class COORDINADOR
{
public:
	COORDINADOR();
	virtual ~COORDINADOR();
	void TECLA(unsigned char key);
	void MUEVE();
	void DIBUJA();
protected:
	MUNDO _MUNDO;
	enum ESTADO { INICIO, JUEGO, FIN, GAMEOVER, PAUSA }; //Diferentes estados del juego. Máquina de estados.
	ESTADO _ESTADO;
};

