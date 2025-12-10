#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H //start of pragma once directive

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

class Shader
{
public:
	GLuint ID;

	Shader(const char* vertexPath, const char* fragmentPath);

	void Activate();
	void Delete();
};

std::string getFileContents(const char* filePath);

#endif //end of pragma once directive
