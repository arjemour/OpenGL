#include "BoxComponent.h"

BoxComponent::BoxComponent(b2World* world, Entity* entity, int objectId)
{
	box = new Box(world, entity->x , entity->y, 1, 1 ,objectId, true, false);
}


BoxComponent::~BoxComponent()
{
}

void BoxComponent::update(Entity& entity)
{
	box->update(&entity);
}
