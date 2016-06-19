#pragma once
#include <vector>

struct Vertex
{
	float x, y, z;
	float nx, ny, nz;
	float r, g, b, a;
};

class CubeModel
{
public:
	CubeModel();
	~CubeModel();

	void drawCube();

private:
	std::vector<Vertex> cubeVertices;
};

