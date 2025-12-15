#include <iostream>
#include "texture.h"

Texture::Texture(const char* imagePath, TextureFilter filterType) {
	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);

	if (filterType == NEAREST) {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	}
	else if (filterType == LINEAR) {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}

	int width, height, nrChannels;
	unsigned char* data = stbi_load(imagePath, &width, &height, &nrChannels, 0);

	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
}

void Texture::Bind() {
	glBindTexture(GL_TEXTURE_2D, ID);
}