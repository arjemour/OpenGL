#include "CubeModelComponent.h"
#include "GL/freeglut.h"
#include <iostream>

CubeModelComponent::CubeModelComponent()
{
	cube = new CubeModel();
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
