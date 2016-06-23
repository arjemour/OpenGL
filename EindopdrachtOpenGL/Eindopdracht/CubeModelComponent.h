#pragma once
#include "Component.h"
#include "CubeModel.h"
#include "Entity.h"

class CubeModelComponent : public Component
{
public:
	CubeModelComponent(GLuint* texture);
	~CubeModelComponent();

	void render(Entity& entity) override;

private:
	CubeModel* cube;
};

