#pragma once
#include "Component.h"
class PlayerMoveComponent : public Component
{
public:
	PlayerMoveComponent();
	~PlayerMoveComponent();

	void update(Entity& entity) override;

private:
	bool left = false;

	void rotate(Entity& entity);
};

