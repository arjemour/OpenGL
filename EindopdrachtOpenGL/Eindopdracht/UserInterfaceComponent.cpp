#include "UserInterfaceComponent.h"
#include <GL/freeglut.h>
#include <string>

extern int deaths;

UserInterfaceComponent::UserInterfaceComponent()
{
}


UserInterfaceComponent::~UserInterfaceComponent()
{
}

void UserInterfaceComponent::update(Entity& entity)
{
}

void UserInterfaceComponent::render(Entity& entity)
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, 1000, 1000, 0, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_TEXTURE_2D);

	glColor3f(1, 1, 1);
	glutBitmapString("Deaths: " + std::to_string(deaths), 500, 20);

	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void UserInterfaceComponent::glutBitmapString(std::string str, int x, int y)
{
	glRasterPos2f(x, y);
	for (int i = 0; i < str.size(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
	}
}
