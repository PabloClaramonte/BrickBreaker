#include "Coordinador.h"
#include "..\ArchivoCabecera(.h)\Coordinador.h"

COORDINADOR::COORDINADOR()
{
	_ESTADO = INICIO;
}

COORDINADOR::~COORDINADOR()
{
	
}

void COORDINADOR::TECLA(unsigned char key)
{
	if (_ESTADO == INICIO) {
		if (key == 'e')
		{
			_MUNDO.INICIALIZA(); 
			_ESTADO = JUEGO;
		}
		if (key == 's')
			exit(0);
    }
    else if (_ESTADO == JUEGO) {
        _MUNDO.TECLADO(key); //Función de las teclas del mundo
    }
    else if (_ESTADO == GAMEOVER)
    {
        if (key == 'c')
            _ESTADO = INICIO;
    }
    else if (_ESTADO == FIN)
    {
        if (key == 'c')
            _ESTADO = INICIO;
    }

}

void COORDINADOR::MUEVE()
{
    if (_ESTADO == JUEGO) {
        _MUNDO.MUEVE(0.025);
    }
}

void COORDINADOR::DIBUJA()
{
    

    if (_ESTADO == INICIO)
    {   
        ETSIDI::playMusica("sonidos/menu.wav", true); //Música de menú

        //CODIGO PARA PINTAR UNA PANTALLA NEGRA CON LETRAS:

        gluLookAt(20,60,40, // Posicion de la camara.
    	20, 0, 20, // Punto hacia el que mira la camara.
    	0, -1, 0); // Vector de autogiro de la camara (No Tocar)

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/menu.png").id);
        glDisable(GL_LIGHTING);
        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);

        glTexCoord3d(0, 1, 0); glVertex3f(0, 0, 0);
        glTexCoord3d(1, 1, 0); glVertex3f(40, 0, 0);
        glTexCoord3d(1, 0, 0); glVertex3f(40, 0, 40);
        glTexCoord3d(0, 0, 0); glVertex3f(0, 0, 40);

        glEnd();
        glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);

        //gluLookAt(0, 7.5, 30, // posicion del ojo
        //    0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
        //    0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

        //ETSIDI::setTextColor(1, 1, 0);
        //ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
        //ETSIDI::printxy("VOXHEAD BETA", -5, 8, 0); 

        //ETSIDI::setTextColor(1, 1, 1);
        //ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
        //ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7, 0);
        //ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6, 0);
        //ETSIDI::printxy("LOS PIBARDOS", 2, 1, 0);
    }
    else if (_ESTADO == JUEGO) {
        //ETSIDI::stopMusica();
        _MUNDO.DIBUJA();
       
    }

    else if (_ESTADO == GAMEOVER)
    {
        _MUNDO.DIBUJA();

        ETSIDI::setTextColor(1, 0, 0);
        ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
        ETSIDI::printxy("GAME OVER", -5, 10, 0);
        ETSIDI::printxy("Pulsa -C- para continuar", -5, 5, 0);
    }

    else if (_ESTADO == FIN)
    {
        _MUNDO.DIBUJA();
        ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
        ETSIDI::printxy("ENHORABUENA, ¡Has ganado!", -5, 10, 0);
        ETSIDI::printxy("Pulsa -C- para continuar", -5, 9, 0);
    }

}

void COORDINADOR::CAMARA()
{
    if (_ESTADO == JUEGO) {
        _MUNDO.CAMARA();
    }
}
