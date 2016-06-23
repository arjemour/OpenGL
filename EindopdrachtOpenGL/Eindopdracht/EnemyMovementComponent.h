#pragma once
#include "Component.h"
#include "Entity.h"

class EnemyMovementComponent : public Component
{
public:
	EnemyMovementComponent(Entity* entity, int minX, int maxX, float maxSpeed);
	~EnemyMovementComponent();

	void update(Entity& entity) override;

private:
	int minX;
	int maxX;
	int startX;
	float maxSpeed;
	bool left = false;

	void rotate(Entity& entity);
};

