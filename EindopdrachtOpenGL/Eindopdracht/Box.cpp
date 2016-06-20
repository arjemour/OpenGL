#include "Box.h"
#include <iostream>

Box::Box(b2World* world, float x, float y, int width, int height, bool isDynamic, bool fixedRotation, float angle) : x(x), y(y), angle(angle), isDynamic(isDynamic), fixedRotation(fixedRotation), world(world)
{
	b2BodyDef bodyDef;
	if (isDynamic) bodyDef.type = b2_dynamicBody;
	else bodyDef.type = b2_staticBody;
	bodyDef.position.Set(x * P2M, y * P2M);
	bodyDef.fixedRotation = fixedRotation;
	bodyDef.angle = angle;
	body = world->CreateBody(&bodyDef);

	b2PolygonShape boxShape;
	boxShape.SetAsBox(P2M * width / 2, P2M * height / 2);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &boxShape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	fixture = body->CreateFixture(&fixtureDef);
}

Box::~Box()
{
	world->DestroyBody(body);
}

void Box::update(Entity* entity)
{
	entity->x = body->GetPosition().x * M2P;
	entity->y = body->GetPosition().y * M2P;
}
