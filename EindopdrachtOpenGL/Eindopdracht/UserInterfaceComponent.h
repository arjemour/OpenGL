#pragma once
#include "Component.h"
#include <string>

class UserInterfaceComponent : public Component
{
public:
	UserInterfaceComponent();
	~UserInterfaceComponent();

	void update(Entity& entity) override;
	void render(Entity& entity) override;

	void glutBitmapString(std::string str, int x, int y);
};

