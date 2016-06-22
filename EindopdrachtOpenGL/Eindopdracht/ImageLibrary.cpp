#include "ImageLibrary.h"
#include <vector>
#include <GL/freeglut.h>
#include "ImageLoader.h"

std::vector<GLuint> images;

ImageLibrary::ImageLibrary()
{
	images.push_back(ImageLoader::loadImage("res/textures/dirt.png", 570, 570));
}


ImageLibrary::~ImageLibrary()
{
}
