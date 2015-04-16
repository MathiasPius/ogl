#include "Precompiled.h"
#include "Bindable.h"
#include "Shader.h"

using namespace ogl;

shader::shader(type aShaderType) :
my_shader(glCreateShader(static_cast<GLenum>(aShaderType)))
{

}

shader::shader(shader &&aMove) :
my_shader(aMove.my_shader)
{
	aMove.my_shader = 0;
}

shader::~shader()
{
	//if (my_shader)
	//	glDeleteShader(my_shader);
}

void shader::source(std::istream &aStream)
{
	assert(!!aStream);

	auto src = std::string(std::istreambuf_iterator<char>(aStream), std::istreambuf_iterator<char>());
	const char *sources = src.c_str();
	int lengths = src.size();
	glShaderSource(my_shader, 1, &sources, &lengths);
}

bool shader::compile()
{
	glCompileShader(my_shader);

	GLint compiled = GL_FALSE;
	glGetShaderiv(my_shader, GL_COMPILE_STATUS, &compiled);

	if (!compiled)
	{
		GLint length = 0;
		glGetShaderiv(my_shader, GL_INFO_LOG_LENGTH, &length);

		auto buffer = std::unique_ptr<char>(new char[length]);
		glGetShaderInfoLog(my_shader, length, &length, buffer.get());

		std::cout << buffer.get() << std::endl;
	}
	
	return (compiled == GL_TRUE);
}
