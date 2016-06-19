#pragma once
#include <vector>
#include "Component.h"

class Entity
{
public:
	float x, y, z;
	bool alive = true;

	std::vector<Component*> components;

	Entity() : x(0), y(0), z(0) {}
	Entity(float x, float y, float z) : x(x), y(y), z(z) {}
	~Entity() {}

	void addComponent(Component* component);
	void update();
	void render();
	std::vector<Component*> getComponents() { return components; }
};

