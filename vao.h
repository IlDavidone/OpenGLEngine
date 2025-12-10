#ifndef VAO_H
#define VAO_H

#include <glad/glad.h>
#include "vbo.h"

class VAO {
	public:
		GLuint ID;

		VAO(); //class constructor

		void LinkAttributes(VBO& VBO, GLuint layout, GLuint componentsNumber, GLenum type, GLsizeiptr stride, void* offset);
		void Bind();
		void Unbind();
		void Delete();
};

#endif
