#include "WorldComponent.h"
#include "MapLoader.h"
#include "GL/freeglut.h"
#include <iostream>

WorldComponent::WorldComponent(std::string mapPath, b2World* world) : world(world)
{
	std::vector<std::vector<int>> map;
	MapLoader::loadMap(mapPath, map);
	float x = 0, y = 0;
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			switch (map[i][j])
			{
			case 0:
				break;
			case 1:
				coords.push_back(new Coords(x, y));
				break;
			}
			x += 2;
		}
		y += 2;
		x = 0;
	}
	Box* box = new Box(world, 0, 0, 228, 1, false, false);
	Box* box2 = new Box(world, 0, 0, 1, 22, false, false);
	Box* box3 = new Box(world, 114, 0, 1, 22, false, false);
	boxes.push_back(box);
	boxes.push_back(box2);
	boxes.push_back(box3);
}

WorldComponent::~WorldComponent()
{
}

void WorldComponent::update(Entity& entity)
{
	world->Step(1.0f / 120.0f, 6, 2);
}

void WorldComponent::render(Entity& entity)
{
	for (auto coord : coords)
	{
		glPushMatrix();
		glTranslatef(coord->x, coord->y, 0.0f);
		cube.drawCube();
		glPopMatrix();
	}
}
