#pragma once
#include <vector>
struct Vertex
{
	float x, y, z;
	float nx, ny, nz;
	float r, g, b, a;
};

class CustomModel
{
public:
	CustomModel();
	~CustomModel();

	void draw();
	void drawCube();

private:
	int rotation = 0;
};

