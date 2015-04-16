#include "Precompiled.h"
#include "Bindable.h"
#include "VertexBuffer.h"

using namespace ogl;

static vertex_buffer::stack_type g_states;

vertex_buffer::vertex_buffer() :
bindable(GL_ARRAY_BUFFER),
my_buffer(generate(glGenBuffers))
{

}

vertex_buffer::~vertex_buffer()
{
	if (my_buffer)
		glDeleteBuffers(1, &my_buffer);
}

vertex_buffer::vertex_buffer(target aTarget) :
bindable(aTarget),
my_buffer(generate(glGenBuffers))
{

}

vertex_buffer::vertex_buffer(vertex_buffer &&aMove) :
bindable(std::forward<bindable>(aMove)),
my_buffer(aMove.my_buffer)
{
	aMove.my_buffer = 0;
}

vertex_buffer::operator GLuint()
{
	return my_buffer;
}

void vertex_buffer::set_data(GLint aSize, const void *aData, usage aUsage)
{
	assert(is_bound());
	glBufferData(bound_to(), aSize, aData, aUsage);
}

void vertex_buffer::set_pointer(GLuint aIndex, unsigned int aCount, pixel_format aPixelFormat, bool aNormalized, unsigned int aStride, unsigned int aOffset)
{
	glVertexAttribPointer(aIndex, aCount, aPixelFormat, aNormalized, aStride, (void *)aOffset);
}

void vertex_buffer::bind(vertex_buffer &aBuffer, GLuint aTarget)
{
	glBindBuffer(aTarget, aBuffer.my_buffer);
}

void vertex_buffer::unbind(vertex_buffer &aBuffer, GLuint aTarget)
{
	glBindBuffer(aTarget, 0);
}

vertex_buffer::stack_type &vertex_buffer::get_states()
{
	return g_states;
}