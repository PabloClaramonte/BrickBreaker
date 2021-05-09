//Zona de declaracion de los #include.
#include <freeglut.h>
#include <Mundo.h>
//Fin zona de declaracion de los #include

//Zona de declaracion de Variables y Clases.
Mundo MUNDO;
//Fin zona de declaracion de Variables y Clases.

//Los CallBack se las funciones se llaman automaticamente cuado suceden los eventos (no hay que llamarlos).
void OnDraw(void); //Funcion de dibujado.
void OnTimer(int value); //Se llama automticamente cuando transcurre un determinado tiempo, asignado por el programador.
void OnKeyboardDown(unsigned char key, int x, int y); //Se llama automaticamente cuando se pulsa una tecla.


int main(int argc, char* argv[])
{
	//Inicializacion de la ventana.
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("VoxHead");

	//Habilitacion de luces y perspectiva.
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registro de los CallBack.
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//Llama periodicamente a la funcion, el primer argumento es el tiempo en "ms" del periodo.
	glutKeyboardFunc(OnKeyboardDown);
	
	MUNDO.Inicializa();
	
	//Pasa el control del programa a la API GLUT.
	glutMainLoop();

	return 0;
}
void OnDraw(void)
{
	//Borra la pantalla y el buffer.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Acciones repetitivas cada ciclo de dibujo.
	
	//CAMARA.SeguimientoPersonaje(HEROE.ValorEspacial_x(), HEROE.ValorEspacial_y(), HEROE.ValorEspacial_z()); //Sigue al personaje en cada ciclo
	
	//Fin de accciones repetitivas.

	//Define el punto de vista.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Inicio c�digo dibujo.
		MUNDO.DibujaEjes();
		MUNDO.Dibuja();
	//Final de codigo de dibujo.

	glutSwapBuffers(); //No borrar este comando ni incluir ninguno mas despues.
}
void OnKeyboardDown(unsigned char key, int x, int y)
{
	//Inicio codigo vinculado al teclado.
	MUNDO.tecla(key);
	//Final codigo vinculado al teclado.

	//No borrar esta linea.
	glutPostRedisplay(); //Redibuja la imagen una vez finaliza la funcion.
}

void OnTimer(int value)
{
	//Inicio codigo vinculado al bucle temporal.
	MUNDO.Mueve();
    //Final codigo vinculado al bucle temporal.
	
	//No borrar estos comandos.
	glutTimerFunc(25, OnTimer, 0); //Necesario para generar interupciones cada "x" ms.
	glutPostRedisplay(); //Redibuja la imagen una vez finaliza la funcion.
}

