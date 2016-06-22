#include "PlayerMoveComponent.h"
#include <Box2D/Box2D.h>
#include "Entity.h"
#include "BoxComponent.h"

extern int direction;

PlayerMoveComponent::PlayerMoveComponent()
{
}

PlayerMoveComponent::~PlayerMoveComponent()
{
}

void PlayerMoveComponent::update(Entity& entity)
{
	for (auto component : entity.getComponents())
	{
		if (dynamic_cast<const BoxComponent*>(component) != nullptr)
		{
			BoxComponent* player = (BoxComponent*)component;
			float impulse = player->box->body->GetMass() / 5;
			switch (direction)
			{
			case 0:
				player->box->body->ApplyLinearImpulseToCenter(b2Vec2(-100, 0.0), true);
				break;
			case 1:
				player->box->body->ApplyLinearImpulseToCenter(b2Vec2(100, 0.0), true);
				break;
			case 2:
				player->box->body->ApplyLinearImpulse(b2Vec2(0, impulse), player->box->body->GetWorldCenter(), true);
				break;
			default:
				break;
			}
			float MAX_SPEED = 2.0f;
			if (player->box->body->GetLinearVelocity().x < -MAX_SPEED) player->box->body->SetLinearVelocity(b2Vec2(-MAX_SPEED, player->box->body->GetLinearVelocity().y));
			else if (player->box->body->GetLinearVelocity().x > MAX_SPEED) player->box->body->SetLinearVelocity(b2Vec2(MAX_SPEED, player->box->body->GetLinearVelocity().y));
		}
	}
}

