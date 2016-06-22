#pragma once
#include <Box2D/Box2D.h>
#include "Component.h"

class WorldContactListener : public b2ContactListener, public Component
{
public:
	WorldContactListener(b2World& world);
	~WorldContactListener();

	void BeginContact(b2Contact* contact) override;


};

