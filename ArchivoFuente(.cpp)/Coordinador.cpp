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
        if (key == 'e' || key == 'E')
        {
            _MUNDO.INICIALIZA();
            _ESTADO = JUEGO;
            ETSIDI::playMusica("sonidos/juego.wav", true);
        }
        if (key == 's' || key == 'S')
            exit(0);
    }
    else if (_ESTADO == JUEGO) {
        _MUNDO.TECLADO(key); //Función de las teclas del mundo
        if (key == 'p' || key == 'P') {
            _ESTADO = PAUSA;
            ETSIDI::playMusica("sonidos/juego.wav", false);
        }
    }
    else if (_ESTADO == GAMEOVER)
    {
        if (key == 'c' || key == 'C')
            _ESTADO = INICIO;
        if (key == 's' || key == 'S')
            exit(0);
    }
    else if (_ESTADO == FIN)
    {
        if (key == 'c' || key == 'C') {
            _ESTADO = INICIO;
            //ETSIDI::playMusica("sonidos/YouWin.wav", false);
        }
        if (key == 's' || key == 'S')
            exit(0);
    }
    else if (_ESTADO == PAUSA)
    {
        if (key == 'c' || key == 'C')
        {
            _ESTADO = JUEGO;
            _MUNDO.MUEVE((float)0.025);
            //ETSIDI::playMusica("sonidos/juego.wav", true);
        }
        if (key == 's')
        {
            _ESTADO = INICIO;
        }
    }
}

void COORDINADOR::MUEVE()
{
    if (_ESTADO == JUEGO) {
        _MUNDO.MUEVE((float)0.025);

        if (_MUNDO.GETZOMBIES() == 0) {
            if (!_MUNDO.CARGARNIVEL()) {
                ETSIDI::playMusica("sonidos/YouWin.wav", false);
                _ESTADO = FIN;
            }
        }

        if (_MUNDO.GETIMPACTO()) {
            _ESTADO = GAMEOVER;
        }
    }
}

void COORDINADOR::DIBUJA()
{
    if (_ESTADO == INICIO)
    {
        gluLookAt(20, 60, 40, // Posicion de la camara.
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
    }

    else if (_ESTADO == JUEGO) {
        _MUNDO.DIBUJA();
    }

    else if (_ESTADO == PAUSA)
    {
        _MUNDO.DIBUJA();
        gluLookAt(20, 60, 40, // Posicion de la camara.
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
    }

    else if (_ESTADO == GAMEOVER)
    {
        _MUNDO.DIBUJA();

        gluLookAt(20, 60, 40, // Posicion de la camara.
            20, 0, 20, // Punto hacia el que mira la camara.
            0, -1, 0); // Vector de autogiro de la camara (No Tocar)

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GameOver.png").id);
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
    }

    else if (_ESTADO == FIN)
    {
        _MUNDO.DIBUJA();

        gluLookAt(20, 60, 40, // Posicion de la camara.
            20, 0, 20, // Punto hacia el que mira la camara.
            0, -1, 0); // Vector de autogiro de la camara (No Tocar)

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/win.png").id);
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
    }

}

void COORDINADOR::CAMARA()
{
    if (_ESTADO == JUEGO) {
        _MUNDO.CAMARA();
    }
}
