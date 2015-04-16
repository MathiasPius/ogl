#include "Precompiled.h"
#include "Bindable.h"
#include "Shader.h"

using namespace ogl;

static program::stack_type g_states;

program::program() :
bindable(GL_PROGRAM),
my_program(glCreateProgram())
{

}

program::~program()
{

}

program::program(program &&aProgram) :
bindable(GL_PROGRAM),
my_program(aProgram.my_program)
{
	aProgram.my_program = 0;
}

program &program::operator=(program &&aProgram)
{
	std::swap(my_program, aProgram.my_program);
	return *this;
}

program::operator GLuint()
{
	return my_program;
}

void program::attach(shader &aShader)
{
	glAttachShader(my_program, aShader.my_shader);
}

void program::detach(shader &aShader)
{
	glDetachShader(my_program, aShader.my_shader);
}

bool program::link()
{
	glLinkProgram(my_program);

	GLint linked = GL_FALSE;
	glGetProgramiv(my_program, GL_LINK_STATUS, &linked);

	detach_all();
	
	if (!linked)
	{
		GLint length = 0;
		glGetProgramiv(my_program, GL_INFO_LOG_LENGTH, &length);

		auto buffer = std::unique_ptr<char>(new char[length]);
		glGetProgramInfoLog(my_program, length, &length, buffer.get());

		std::cout << buffer.get() << std::endl;
	}

	return (linked == GL_TRUE);
}

program::uniform program::get_uniform(const std::string &aName)
{
	assert(is_bound());
	return uniform(this, glGetUniformLocation(my_program, aName.c_str()));
}

program::uniform program::get_uniform(GLuint aLocation)
{
	return uniform(this, aLocation);
}

void program::detach_all()
{
	GLint attached = 0;
	glGetProgramiv(my_program, GL_ATTACHED_SHADERS, &attached);

	auto shaders = std::unique_ptr<GLuint>(new GLuint[attached]);
	glGetAttachedShaders(my_program, attached, &attached, shaders.get());

	for (auto i = 0; i < attached; i++)
		glDetachShader(my_program, shaders.get()[i]);
}

ogl::program ogl::quick_shader(std::initializer_list<std::string> aShaders)
{
	program prog;

	for (auto &str : aShaders)
	{
		std::string extension = str.substr(str.find_last_of(".") + 1);
		shader shd = shader((extension == "vert") ? shader::vertex_shader : shader::fragment_shader);

		shd.source(std::ifstream(str));
		shd.compile();
		prog.attach(shd);
	}

	prog.link();
	return std::move(prog);
}

void program::bind(program &aBindable, GLuint aConstant)
{
	glUseProgram(aBindable.my_program);
}

void program::unbind(program &aBindable, GLuint aConstant)
{
	glUseProgram(0);
}

program::stack_type &program::get_states()
{
	return g_states;
}