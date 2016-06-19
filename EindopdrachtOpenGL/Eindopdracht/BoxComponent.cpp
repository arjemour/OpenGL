#include "BoxComponent.h"

BoxComponent::BoxComponent(b2World* world, Entity* entity)
{
	box = new Box(world, entity->x , entity->y, 1, 1 , true, true);
}


BoxComponent::~BoxComponent()
{
}

void BoxComponent::update(Entity& entity)
{
	box->update(&entity);
}
