#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H //start of pragma once directive

#include "includes.h"

class Shader
{
public:
	GLuint ID;

	Shader(const char* vertexPath, const char* fragmentPath);

	void Activate();
	void setColorUniform();
	void setDirectionalLightUniforms();
	void setPointLightUniforms();
	void setSpotlightUniforms(Camera& camera);
	void setMaterialUniforms();
	void Delete();
};

std::string getFileContents(const char* filePath);

#endif //end of pragma once directive
