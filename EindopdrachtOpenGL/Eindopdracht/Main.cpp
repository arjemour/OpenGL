#include <GL/freeglut.h>
#include "Window.h"
#include "Engine.h"
#include "ObjLibrary.h"
#include "ImageLibrary.h"

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	Window window;
	ObjLibrary * lib = new ObjLibrary();
	ImageLibrary iLib;
	lib->loadObjects();
	Engine engine;
	glutMainLoop();


	return 0;
}
