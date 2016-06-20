#pragma once
#include "Component.h"
#include "Box.h"
#include "Entity.h";

class BoxComponent : public Component
{
public:
	BoxComponent(b2World* world, Entity* entity);
	~BoxComponent();

	void update(Entity& entity) override;
	Box* box;
};

