#pragma once
#include "Component.h"
#include <vector>
#include "CubeModel.h"
#include <Box2D/Box2D.h>
#include "Box.h"
#include "CustomModel.h"

struct Coords
{
	float x;
	float y;

	Coords(float x, float y) : x(x), y(y) {};
};

class WorldComponent : public Component
{
public:
	WorldComponent(std::string mapPath, b2World* world);
	~WorldComponent();

	void update(Entity& entity) override;
	void render(Entity& entity) override;

private:
	std::vector<Box*> boxes;
	std::vector<Coords*> dirtCoords;
	std::vector<Coords*> clayCoords;
	CubeModel* dirtCube;
	CubeModel* clayCube;
	b2World* world;
	CustomModel model;
};

