#pragma once
#include <string>
#include <GL/freeglut.h>

class ImageLoader
{
public:
	static GLuint loadImage(std::string filepath, int width, int height);
};

