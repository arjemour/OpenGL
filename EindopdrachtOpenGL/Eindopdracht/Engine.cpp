#include "Engine.h"
#include "Entity.h"
#include <Box2D/Box2D.h>
#include "CubeModelComponent.h"
#include "WorldComponent.h"
#include "BoxComponent.h"
#include "PlayerMoveComponent.h"
#include "ObjModelComponent.h"
#include "EnemyMovementComponent.h"
#include "WorldContactListener.h"
#include "ObjectIdLibrary.h"
#include "UserInterfaceComponent.h"

b2World* world;
std::vector<Entity*> entities;
extern std::vector<pair<string, ObjModel*>> objectLibrary;

Engine::Engine()
{
	b2Vec2 gravity(0.0f, -9.81f);
	world = new b2World(gravity);

	auto* worldEntity = new Entity(0, 0, 0);
	worldEntity->addComponent(new WorldComponent("res/maps/map.txt", world));
	worldEntity->addComponent(new WorldContactListener(*world));
	entities.push_back(worldEntity);

	auto* player = new Entity(10, 3, 0);
	player->addComponent(new ObjModelComponent(objectLibrary[0].second));
	player->addComponent(new BoxComponent(world, player, playerId));
	player->addComponent(new PlayerMoveComponent);
	entities.push_back(player);

	auto* enemy = new Entity(60, 2, 0);
	enemy->addComponent(new ObjModelComponent(objectLibrary[1].second));
	enemy->addComponent(new BoxComponent(world, enemy, enemyId));
	enemy->addComponent(new EnemyMovementComponent(enemy, 10, 10, 0.5f));
	entities.push_back(enemy);

	auto* enemy2 = new Entity(100, 2, 0);
	enemy2->addComponent(new ObjModelComponent(objectLibrary[1].second));
	enemy2->addComponent(new BoxComponent(world, enemy2, enemyId));
	enemy2->addComponent(new EnemyMovementComponent(enemy2, 10, 10, 0.5f));
	entities.push_back(enemy2);

	auto* gui = new Entity(0, 0, 0);
	gui->addComponent(new UserInterfaceComponent);
	entities.push_back(gui);
}

Engine::~Engine()
{
}
