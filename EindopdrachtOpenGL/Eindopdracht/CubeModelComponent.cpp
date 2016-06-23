#include "CubeModelComponent.h"
#include "GL/freeglut.h"
#include <iostream>

CubeModelComponent::CubeModelComponent(GLuint* texture)
{
	cube = new CubeModel(texture);
}

CubeModelComponent::~CubeModelComponent()
{
}

void CubeModelComponent::render(Entity& entity)
{
	glPushMatrix();
	glTranslatef(entity.x, entity.y, entity.z);
	cube->drawCube();
	glPopMatrix();
}
