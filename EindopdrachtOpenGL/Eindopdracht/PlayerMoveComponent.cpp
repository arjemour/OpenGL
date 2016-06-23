#include "PlayerMoveComponent.h"
#include <Box2D/Box2D.h>
#include "Entity.h"
#include "BoxComponent.h"
#include "ObjModelComponent.h"

extern int direction;

PlayerMoveComponent::PlayerMoveComponent()
{
}

PlayerMoveComponent::~PlayerMoveComponent()
{
}

void PlayerMoveComponent::update(Entity& entity)
{
	float MAX_SPEED;
	for (auto component : entity.getComponents())
	{
		if (dynamic_cast<const BoxComponent*>(component) != nullptr)
		{
			BoxComponent* player = (BoxComponent*)component;
			float impulse = player->box->body->GetMass() * 1.5f;
			switch (direction)
			{
			case 0:
				MAX_SPEED = 1;
				player->box->body->ApplyLinearImpulseToCenter(b2Vec2(-100, 0.0), true);
				left = true;
				rotate(entity);
				break;
			case 1:
				MAX_SPEED = 1;
				player->box->body->ApplyLinearImpulseToCenter(b2Vec2(100, 0.0), true);
				left = false;
				rotate(entity);
				break;
			case 2:
				MAX_SPEED = 1;
				player->box->body->ApplyLinearImpulse(b2Vec2(0, impulse), player->box->body->GetWorldCenter(), true);
				break;
			default:
				MAX_SPEED = 0;
				break;
			}
			
			if (player->box->body->GetLinearVelocity().x < -MAX_SPEED) player->box->body->SetLinearVelocity(b2Vec2(-MAX_SPEED, player->box->body->GetLinearVelocity().y));
			else if (player->box->body->GetLinearVelocity().x > MAX_SPEED) player->box->body->SetLinearVelocity(b2Vec2(MAX_SPEED, player->box->body->GetLinearVelocity().y));
		}
	}
}

void PlayerMoveComponent::rotate(Entity& entity)
{
	for (auto component : entity.getComponents())
	{
		if (dynamic_cast<const ObjModelComponent*>(component) != nullptr)
		{
			ObjModelComponent* rotate = (ObjModelComponent*)component;
			if (left) rotate->setRotation(180);
			else rotate->setRotation(0);
		}
	}
}

