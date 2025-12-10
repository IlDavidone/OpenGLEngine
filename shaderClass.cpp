#include "shaderClass.h"

std::string getFileContents(const char* filePath) { //temporary function to read shader files
	std::string contents;
	std::ifstream file(filePath);

	if (!file.is_open()) {
		std::cerr << "Could not open the file: " << filePath << std::endl;
		return "";
	}

	std::string fileBuffer;

	while (std::getline(file, fileBuffer))
		contents += fileBuffer + "\n";

	file.close();
	return contents;
}

Shader::Shader(const char* vertexFilePath, const char* fragmentFilePath) {
	std::string vertexCode{ getFileContents(vertexFilePath) };
	std::string fragmentCode{ getFileContents(fragmentFilePath) };

	const char* vertexSource{ vertexCode.c_str() };
	const char* fragmentSource{ fragmentCode.c_str() };

	GLuint vertexShader{ glCreateShader(GL_VERTEX_SHADER) };
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader{ glCreateShader(GL_FRAGMENT_SHADER) };
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	ID = { glCreateProgram() };
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::Activate() {
	glUseProgram(ID);
}

void Shader::Delete() {
	glDeleteProgram(ID);
}

