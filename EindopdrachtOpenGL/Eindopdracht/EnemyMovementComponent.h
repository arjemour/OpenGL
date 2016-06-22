#pragma once
#include "Component.h"
#include "Entity.h"

class EnemyMovementComponent : public Component
{
public:
	EnemyMovementComponent(int minX, int maxX);
	~EnemyMovementComponent();

	void update(Entity& entity) override;

private:
	int minX;
	int maxX;
	bool left = false;

	void rotate(Entity& entity);
};

