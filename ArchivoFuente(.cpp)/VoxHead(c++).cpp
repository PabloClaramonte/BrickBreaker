//Zona de declaracion de los #include.
#include <freeglut.h>
#include <CamaraDeVision.h>
#include <Jugador.h>
//Fin zona de declaracion de los #include

//Zona de declaracion de Variables y Clases.
CamaraDeVision CAMARA;
Jugador SANTIAGO;

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

	//Pasa el control del programa a la API GLUT.
	glutMainLoop();

	return 0;
}
void OnDraw(void)
{
	//Borra la pantalla y el buffer.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Acciones repetitivas cada ciclo de dibujo.
	CAMARA.SeguimientoPersonaje(SANTIAGO.ValorEspacial_x(), SANTIAGO.ValorEspacial_y(), SANTIAGO.ValorEspacial_z());
	//Fin de accciones repetitivas.

	//Define el punto de vista.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(CAMARA.P_x(), CAMARA.P_y(),CAMARA.P_z(), // Posicion de la camara.
		CAMARA.A_x(),CAMARA.A_y(),CAMARA.A_z(), // Punto hacia el que mira la camara.
		CAMARA.S_x(),CAMARA.S_y(),CAMARA.S_z()); // Vector de autogiro de la camara (No Tocar).   

	//Inicio del codigo de dibujo.
	
	//Eje cartesiano para aclararnos: X = Rojo; Y = Verde; Z = Azul.
		glBegin(GL_LINES);
		glColor3f(1, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);
		glEnd();

		glBegin(GL_LINES);
		glColor3f(0, 1, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 1, 0);
		glEnd();

		glBegin(GL_LINES);
		glColor3f(0, 0, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 1);
		glEnd();
    //Fin eje cartesiano.


		SANTIAGO.Dibuja();
	
	//Final de codigo de dibujo.

	glutSwapBuffers(); //No borrar este comando ni incluir ninguno mas despues.
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//Inicio codigo vinculado al teclado.
	SANTIAGO.Mueve(key);
	

	//Final codigo vinculado al teclado.


	//No borrar esta linea.
	glutPostRedisplay(); //Redibuja la imagen una vez finaliza la funcion.
}

void OnTimer(int value)
{
	//Inicio codigo vinculado al bucle temporal.

    //Final codigo vinculado al bucle temporal.

	//No borrar estos comandos.
	glutTimerFunc(25, OnTimer, 0); //Necesario para generar interupciones cada "x" ms.
	glutPostRedisplay(); //Redibuja la imagen una vez finaliza la funcion.
}

