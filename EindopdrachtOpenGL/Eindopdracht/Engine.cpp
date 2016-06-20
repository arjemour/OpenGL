#include "Engine.h"
#include "Entity.h"
#include <Box2D/Box2D.h>
#include "CubeModelComponent.h"
#include "WorldComponent.h"
#include "BoxComponent.h"

b2World* world;
std::vector<Entity*> entities;
//extern std::vector<std::pair<std::string, ObjModel*>> objectLibrary;

Engine::Engine()
{
	b2Vec2 gravity(0.0f, -9.81f);
	world = new b2World(gravity);

	auto* worldEntity = new Entity(0, 0, 0);
	worldEntity->addComponent(new WorldComponent("res/maps/map.txt", world));
	entities.push_back(worldEntity);

	auto* player = new Entity(10, 100, 0);
	player->addComponent(new CubeModelComponent());
	player->addComponent(new BoxComponent(world, player));
	entities.push_back(player);
}

Engine::~Engine()
{
}
