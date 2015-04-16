#include "Precompiled.h"
#include "Bindable.h"
#include "VertexArray.h"

using namespace ogl;

static vertex_array::stack_type g_states;

vertex_array::vertex_array() :
bindable(GL_VERTEX_ARRAY),
my_buffer(generate(glGenVertexArrays))
{

}

vertex_array::~vertex_array()
{
	if (my_buffer)
		glDeleteVertexArrays(1, &my_buffer);
}

vertex_array::vertex_array(vertex_array &&aMove) :
bindable(std::forward<bindable>(aMove)),
my_buffer(aMove.my_buffer)
{
	aMove.my_buffer = 0;
}

vertex_array::operator GLuint()
{
	return my_buffer;
}

void vertex_array::enable_array(GLuint aIndex)
{
	assert(is_bound());
	glEnableVertexAttribArray(aIndex);
}

void vertex_array::enable_arrays(std::vector<GLuint> aIndices)
{
	assert(is_bound());

	for (auto &index : aIndices)
		glEnableVertexAttribArray(index);
}

void vertex_array::bind(vertex_array &aBuffer, GLuint aTarget)
{
	glBindVertexArray(aBuffer.my_buffer);
}

void vertex_array::unbind(vertex_array &aBuffer, GLuint aTarget)
{
	glBindVertexArray(0);
}

vertex_array::stack_type &vertex_array::get_states()
{
	return g_states;
}