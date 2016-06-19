#include "MapLoader.h"
#include <fstream>
#include <sstream>

void MapLoader::loadMap(std::string mapPath, std::vector<std::vector<int>>& map)
{
	int y = 0;
	std::string line, value;
	std::ifstream file;
	file.open(mapPath);
	while (!file.eof())
	{
		std::vector<int> column;
		map.push_back(column);
		getline(file, line);
		std::istringstream temp(line);
		while (getline(temp, value, ','))
		{
			map[y].push_back(atoi(value.c_str()));
		}
		y++;
	}
	file.close();
	reverse(map.begin(), map.end());
}