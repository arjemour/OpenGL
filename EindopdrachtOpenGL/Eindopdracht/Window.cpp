#include "Window.h"
#include <GL/freeglut.h>
#include <cstdio>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include "CubeModel.h"
#include "Entity.h"
#include <Box2D/Box2D.h>
float lowerX = -25.0f, upperX = 25.0f, lowerY = -25.0f, upperY = 25.0f;
int fps = 60;
float timePerTick = 1000 / fps;
float delta = 0;
long timeSinceStart = 0;
long oldTimeSinceStart = 0;
float timer = 0;
int ticks = 0;

int width, height;
float lastFrameTime = 0;
bool keys[255];
bool justMoved = false;
CubeModel cube;
extern std::vector<Entity*> entities;
extern b2World* world;
std::vector<Entity*> entitiesToAdd;

struct Camera
{
	float posX = 0;
	float posY = -4;
	float rotX = 0;
	float rotY = 0;
} camera;

Window::Window()
{
	width = 1920;
	height = 1080;
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(width, height);

	glutCreateWindow("Hello World");

	memset(keys, 0, sizeof(keys));
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glutIdleFunc(idle);
	glutDisplayFunc(display);
	glutReshapeFunc([](int w, int h) { width = w; height = h; glViewport(0, 0, w, h); });
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardUp);
	glutPassiveMotionFunc(passiveMotion);

	glutWarpPointer(width / 2, height / 2);
}


Window::~Window()
{
}

void update()
{
	if (entitiesToAdd.size() > 0)
	{
		for each(Entity* e in entitiesToAdd)
		{
			entities.push_back(e);
		}
		entitiesToAdd.clear();
	}

	for (auto entity : entities) entity->update();

	for (std::vector<Entity*>::iterator it = entities.begin(); it != entities.end();)
	{
		if (!(*it)->alive)
		{
			for (std::vector<Component*>::iterator it2 = (*it)->components.begin(); it2 != (*it)->components.end();)
			{
				delete (*it2);
				(*it)->components.erase(it2);
			}
			delete (*it);
			it = entities.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void Window::idle()
{
	float frameTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
	float deltaTime = frameTime - lastFrameTime;
	lastFrameTime = frameTime;

	const float speed = 3;
	if (keys['a']) move(0, deltaTime*speed);
	if (keys['d']) move(180, deltaTime*speed);
	if (keys['w']) move(90, deltaTime*speed);
	if (keys['s']) move(270, deltaTime*speed);

	timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	delta += (timeSinceStart - oldTimeSinceStart) / timePerTick;
	timer += timeSinceStart - oldTimeSinceStart;
	oldTimeSinceStart = timeSinceStart;
	if (delta >= 1)
	{
		update();
		glutPostRedisplay();
		ticks++;
		delta--;
	}

	if (timer >= 1000)
	{
		timer = 0;
		ticks = 0;
	}
}

void Window::display()
{
	glClearColor(0.6f, 0.6f, 1, 1);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, (float)width / height, 0.1, 1000);
	//gluOrtho2D(lowerX, upperX, lowerY, upperY);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(camera.rotX, 1, 0, 0);
	glRotatef(camera.rotY, 0, 1, 0);
	//glTranslatef(1, 1.5f, 0);
	glTranslatef(camera.posX, 0, camera.posY);

	float pos[4] = { 0.5, 1, -1, 0 };
	glLightfv(GL_LIGHT0, GL_POSITION, pos);


	glColor3f(0.1f, 1.0f, 0.2f);
/*	glBegin(GL_QUADS);
	glVertex3f(-15, -1, -15);
	glVertex3f(15, -1, -15);
	glVertex3f(15, -1, 15);
	glVertex3f(-15, -1, 15);
	glEnd();*/

	for (auto entity : entities) entity->render();

	glutSwapBuffers();
}

void Window::passiveMotion(int x, int y)
{
	if (justMoved)
	{
		justMoved = false;
		return;
	}
	int dx = x - width / 2;
	int dy = y - height / 2;
	if ((dx != 0 || dy != 0) && abs(dx) < 400 && abs(dy) < 400)
	{
		camera.rotY += dx / 10.0f;
		camera.rotX += dy / 10.0f;
		glutWarpPointer(width / 2, height / 2);
		justMoved = true;
	}
}

void Window::keyboard(unsigned char key, int, int)
{
	if (key == 27)
		exit(0);
	keys[key] = true;
}

void Window::keyboardUp(unsigned char key, int, int)
{
	keys[key] = false;
}

void Window::move(float angle, float fac)
{
	camera.posX += (float)cos((camera.rotY + angle) / 180 * M_PI) * fac;
	camera.posY += (float)sin((camera.rotY + angle) / 180 * M_PI) * fac;
}

