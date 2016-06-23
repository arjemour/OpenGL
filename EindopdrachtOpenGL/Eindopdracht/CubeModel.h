#pragma once
#include <GL/freeglut.h>

struct Vertex
{
	float x, y, z;
	float nx, ny, nz;
	float r, g, b, a;
};

class CubeModel
{
public:
	CubeModel(GLuint* texture);
	~CubeModel();

	void drawCube();

private:
	GLuint* texture;
};

