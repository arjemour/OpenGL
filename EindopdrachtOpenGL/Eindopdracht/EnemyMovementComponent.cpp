#include "EnemyMovementComponent.h"
#include <Box2D/Box2D.h>
#include "BoxComponent.h"
#include "ObjModelComponent.h"

EnemyMovementComponent::EnemyMovementComponent(int minX, int maxX) : minX(minX), maxX(maxX)
{
}


EnemyMovementComponent::~EnemyMovementComponent()
{
}

void EnemyMovementComponent::update(Entity& entity)
{
	for (auto component : entity.getComponents())
	{
		if (dynamic_cast<const BoxComponent*>(component) != nullptr)
		{
			BoxComponent* player = (BoxComponent*)component;
			if (minX >= entity.x)
			{
				left = false;
				rotate(entity);
			}
			if (maxX <= entity.x)
			{
				left = true;
				rotate(entity);
			}
			if (left) player->box->body->ApplyLinearImpulseToCenter(b2Vec2(-100, 0.0), true);
			else player->box->body->ApplyLinearImpulseToCenter(b2Vec2(100, 0.0), true);

			float MAX_SPEED = 0.5f;
			if (player->box->body->GetLinearVelocity().x < -MAX_SPEED) player->box->body->SetLinearVelocity(b2Vec2(-MAX_SPEED, player->box->body->GetLinearVelocity().y));
			else if (player->box->body->GetLinearVelocity().x > MAX_SPEED) player->box->body->SetLinearVelocity(b2Vec2(MAX_SPEED, player->box->body->GetLinearVelocity().y));
		}
	}
}

void EnemyMovementComponent::rotate(Entity& entity)
{
	for (auto component : entity.getComponents())
	{
		if (dynamic_cast<const ObjModelComponent*>(component) != nullptr)
		{
			ObjModelComponent* rotate = (ObjModelComponent*)component;
			if(left) rotate->setRotation(180);
			else rotate->setRotation(0);
		}
	}
}
