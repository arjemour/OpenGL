#pragma once
#include <Box2D/Box2D.h>
#include "Entity.h"
class Box
{
public:
	b2Body* body;

	Box(b2World* world, float x, float y, int width, int height, int objectId, bool isDynamic, bool fixedRotation, float angle = 0.0f);
	~Box();
	void update(Entity* entity);
	void reset(Entity* entity);

private:
	float x;
	float y;
	float angle;
	bool isDynamic;
	bool fixedRotation;
	bool resetPos = false;

	b2World* world;
	b2Fixture* fixture;

	const float M2P = 60;
	const float P2M = 1 / M2P;
};

