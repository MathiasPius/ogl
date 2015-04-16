#include "Precompiled.h"
#include "Utility.h"

GLuint ogl::generate(std::function<void(GLuint, GLuint*)> aGeneratorFunction)
{
	GLuint temp = 0;
	aGeneratorFunction(1, &temp);
	return temp;
}