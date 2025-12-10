#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include "stb_image.h"

enum TextureFilter {
	NEAREST,
	LINEAR,
};

class Texture {
public:
	GLuint ID;

	Texture(const char* imagePath, TextureFilter filterType);

	void Bind();
};



#endif
