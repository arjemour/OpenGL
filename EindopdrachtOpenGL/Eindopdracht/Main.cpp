#include <GL/freeglut.h>
#include "Window.h"
#include "Engine.h"

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	Window window;
	Engine engine;
	glutMainLoop();


	return 0;
}
