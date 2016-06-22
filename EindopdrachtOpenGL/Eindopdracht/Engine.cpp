#include "Engine.h"
#include "Entity.h"
#include <Box2D/Box2D.h>
#include "CubeModelComponent.h"
#include "WorldComponent.h"
#include "BoxComponent.h"
#include "PlayerMoveComponent.h"
#include "ObjModelComponent.h"
#include "EnemyMovementComponent.h"

b2World* world;
std::vector<Entity*> entities;
extern std::vector<pair<string, ObjModel*>> objectLibrary;

Engine::Engine()
{
	b2Vec2 gravity(0.0f, -9.81f);
	world = new b2World(gravity);

	auto* worldEntity = new Entity(0, 0, 0);
	worldEntity->addComponent(new WorldComponent("res/maps/map.txt", world));
	entities.push_back(worldEntity);

	auto* player = new Entity(10, 100, 0);
	player->addComponent(new ObjModelComponent(objectLibrary[0].second));
	player->addComponent(new BoxComponent(world, player));
	player->addComponent(new PlayerMoveComponent);
	entities.push_back(player);

	auto* box = new Entity(70, 2, 0);
	box->addComponent(new ObjModelComponent(objectLibrary[1].second));
	box->addComponent(new BoxComponent(world, box));
	box->addComponent(new EnemyMovementComponent(70, 80));
	entities.push_back(box);
}

Engine::~Engine()
{
}
