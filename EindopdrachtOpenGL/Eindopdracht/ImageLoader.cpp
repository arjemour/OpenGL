#include "ImageLoader.h"
#include "stb_image.h"
#include "GL/freeglut.h"

GLuint* ImageLoader::loadImage(std::string filepath, int width, int height)
{
	GLuint* textureId = new GLuint;
	width = 32;
	height = 32;
	int bpp = 32;
	unsigned char* image = stbi_load(filepath.c_str(), &width, &height, &bpp, 4);
	if (image == nullptr)
		throw(std::string("Failed to load texture"));
	glGenTextures(1, textureId);
	glBindTexture(GL_TEXTURE_2D, *textureId);
	glTexImage2D(GL_TEXTURE_2D,
		0,		//level
		GL_RGBA,		//internal format
		32,		//width
		32,		//height
		0,		//border
		GL_RGBA,		//data format
		GL_UNSIGNED_BYTE,	//data type
		image);		//data
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_image_free(image);
	return textureId;
}
