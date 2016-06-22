#include "ObjModelComponent.h"
#include "Entity.h"

void ObjModelComponent::render(Entity& entity)
{
	objModel->draw(entity, scale, rotation);
}
