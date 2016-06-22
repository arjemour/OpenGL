#include "WorldContactListener.h"
#include <iostream>
#include <vector>
#include "ObjectIdLibrary.h"
#include "Entity.h"
#include "PlayerMoveComponent.h"
#include "EnemyMovementComponent.h"
#include "BoxComponent.h"

extern std::vector<Entity*> entities;

WorldContactListener::WorldContactListener(b2World& world)
{
	world.SetContactListener(this);
}


WorldContactListener::~WorldContactListener()
{
}

void WorldContactListener::BeginContact(b2Contact* contact)
{
	Entity* player = new Entity;
	int bodyUserData1 = (int)contact->GetFixtureA()->GetBody()->GetUserData();
	int bodyUserData2 = (int)contact->GetFixtureB()->GetBody()->GetUserData();
	if ((bodyUserData1 == playerId || bodyUserData2 == playerId) && (bodyUserData1 == enemyId || bodyUserData2 == enemyId))
	{
		for(auto entity : entities)
		{
			for(auto component : entity->getComponents())
			{
				if (dynamic_cast<const PlayerMoveComponent*>(component) != nullptr) player = entity;
				if (dynamic_cast<const EnemyMovementComponent*>(component) != nullptr)
				{
					if(entity->x <= player->x + 3 && entity->x >= player->x - 3)
					{
						for (auto component2 : player->getComponents())
						{
							if (dynamic_cast<const BoxComponent*>(component2) != nullptr)
							{
								BoxComponent* move = (BoxComponent*)component2;
								move->box->reset(player);
								std::cout << "test";
							}
						}
					}
				}
			}
		}
	}
}
