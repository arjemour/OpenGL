#pragma once
#include <GL/freeglut.h>

class CubeModel
{
public:
	CubeModel(GLuint* texture);
	~CubeModel();

	void drawCube();

private:
	GLuint* texture;
};

