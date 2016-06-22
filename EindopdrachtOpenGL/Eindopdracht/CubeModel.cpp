#include "CubeModel.h"
#include <GL/freeglut.h>

extern std::vector<GLuint> images;

CubeModel::CubeModel()
{
	cubeVertices.push_back(Vertex{ -1, -1, -1, 0,0,1, 1,1,1,1 });
	cubeVertices.push_back(Vertex{ -1,  1, -1, 0,0,1, 1,1,1,1 });
	cubeVertices.push_back(Vertex{ 1,  1, -1, 0,0,1, 1,1,1,1 });
	cubeVertices.push_back(Vertex{ 1, -1, -1, 0,0,1, 1,1,1,1 });

	cubeVertices.push_back(Vertex{ -1, -1,  1, 0,0,-1, 1,1,1,1 });
	cubeVertices.push_back(Vertex{ -1,  1,  1, 0,0,-1, 1,1,1,1 });
	cubeVertices.push_back(Vertex{ 1,  1,  1, 0,0,-1, 1,1,1,1 });
	cubeVertices.push_back(Vertex{ 1, -1,  1, 0,0,-1, 1,1,1,1 });

	cubeVertices.push_back(Vertex{ -1,  -1, -1,		0,-1,0,		1,1,1,1 });
	cubeVertices.push_back(Vertex{ -1,  -1,  1,		0,-1,0,		1,1,1,1 });
	cubeVertices.push_back(Vertex{ 1,  -1,  1,		0,-1,0,		1,1,1,1 });
	cubeVertices.push_back(Vertex{ 1,  -1, -1,		0,-1,0,		1,1,1,1 });

	cubeVertices.push_back(Vertex{ -1,  1, -1,		0,1,0,		1,1,1,1 });
	cubeVertices.push_back(Vertex{ -1,  1,  1,		0,1,0,		1,1,1,1 });
	cubeVertices.push_back(Vertex{ 1,  1,  1,		0,1,0,		1,1,1,1 });
	cubeVertices.push_back(Vertex{ 1,  1, -1,		0,1,0,		1,1,1,1 });

	cubeVertices.push_back(Vertex{ -1, -1, -1,		-1,0,0,		1,1,1,1 });
	cubeVertices.push_back(Vertex{ -1, -1,  1,		-1,0,0,		1,1,1,1 });
	cubeVertices.push_back(Vertex{ -1,  1,  1,		-1,0,0,		1,1,1,1 });
	cubeVertices.push_back(Vertex{ -1,  1, -1,		-1,0,0,		1,1,1,1 });

	cubeVertices.push_back(Vertex{ 1, -1, -1,		1,0,0,		1,1,1,1 });
	cubeVertices.push_back(Vertex{ 1, -1,  1,		1,0,0,		1,1,1,1 });
	cubeVertices.push_back(Vertex{ 1,  1,  1,		1,0,0,		1,1,1,1 });
	cubeVertices.push_back(Vertex{ 1,  1, -1,		1,0,0,		1,1,1,1 });
}


CubeModel::~CubeModel()
{
}

void CubeModel::drawCube()
{
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBindTexture(GL_TEXTURE_2D, images.at(0));

	glBegin(GL_QUADS);			
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// Top Left Of The Texture and Quad

																// Back Face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);	// Bottom Left Of The Texture and Quad

																// Top Face
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);	// Top Right Of The Texture and Quad

																// Bottom Face
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);	// Bottom Right Of The Texture and Quad

																// Right face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);	// Bottom Left Of The Texture and Quad

																// Left Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);	// Top Left Of The Texture and Quad
	glEnd();					// Done Drawing The Cube

	glDisable(GL_TEXTURE_2D);
}
