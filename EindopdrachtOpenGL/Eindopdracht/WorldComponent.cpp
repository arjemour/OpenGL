#include "WorldComponent.h"
#include "MapLoader.h"
#include "GL/freeglut.h"
#include <iostream>
#include "ObjectIdLibrary.h"
#include "CustomModel.h"

extern std::vector<GLuint*> images;
WorldComponent::WorldComponent(std::string mapPath, b2World* world) : world(world)
{
	dirtCube = new CubeModel(images.at(0));
	clayCube = new CubeModel(images.at(1));
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
				dirtCoords.push_back(new Coords(x, y));
				break;
			case 2:
				clayCoords.push_back(new Coords(x, y));
			}
			x += 2;
		}
		y += 2;
		x = 0;
	}

	Box* box = new Box(world, 0, 0, 228, 1, boxId, false, false);
	Box* box2 = new Box(world, 0, 0, 1, 44, boxId, false, false);
	Box* box3 = new Box(world, 114, 0, 1, 44, boxId, false, false);
	Box* box4 = new Box(world, 7, 6, 2, 1, boxId, false, false);
	Box* box5 = new Box(world, 23, 10, 2, 1, boxId, false, false);
	Box* box6 = new Box(world, 33, 4, 2, 1, boxId, false, false);
	Box* box7 = new Box(world, 56, 6, 4, 1, boxId, false, false);
	Box* box8 = new Box(world, 86, 6, 4, 1, boxId, false, false);
	boxes.push_back(box);
	boxes.push_back(box2);
	boxes.push_back(box3);
	boxes.push_back(box4);
	boxes.push_back(box5);
	boxes.push_back(box6);
	boxes.push_back(box7);
	boxes.push_back(box8);
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
	for (auto coord : dirtCoords)
	{
		glPushMatrix();
		glTranslatef(coord->x, coord->y, 0.0f);
		dirtCube->drawCube();
		glPopMatrix();
	}
	for (auto coord : clayCoords)
	{
		glPushMatrix();
		glTranslatef(coord->x, coord->y, 0.0f);
		clayCube->drawCube();
		glPopMatrix();
	}
	
	glPushMatrix();
	glTranslatef(40, 15, 0);
	model.draw();
	glPopMatrix();
}
