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
	void CAMARA();
protected:
	MUNDO _MUNDO;
	enum ESTADO { INICIO, JUEGO, FIN, GAMEOVER, PAUSA }; //Diferentes estados del juego. M�quina de estados.
	ESTADO _ESTADO;
};

