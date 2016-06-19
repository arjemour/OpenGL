#pragma once
#include <vector>

class MapLoader
{
public:
	static void loadMap(std::string mapPath, std::vector<std::vector<int>>& map);
};

