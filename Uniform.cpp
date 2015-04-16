#include "Precompiled.h"
#include "Shader.h"

using namespace ogl;

program::uniform::uniform() :
my_program(nullptr),
my_location(0)
{}

program::uniform::uniform(program *aProgram, GLuint aLocation) :
my_program(aProgram),
my_location(aLocation)
{}

program::uniform::uniform(uniform &&aUniform) :
my_program(aUniform.my_program),
my_location(aUniform.my_location)
{}

program::uniform &program::uniform::operator=(program::uniform &&aUniform)
{
	my_program = std::move(aUniform.my_program);
	my_location = std::move(aUniform.my_location);

	return *this;
}

program::uniform::~uniform()
{}