#include "Precompiled.h"
#include "RenderBuffer.h"
#include "Bindable.h"
#include "Utility.h"

using namespace ogl;

static render_buffer::stack_type g_states;

render_buffer::render_buffer() :
bindable(GL_RENDERBUFFER),
my_buffer(generate(glGenRenderbuffers))
{

}

render_buffer::~render_buffer()
{

}

void render_buffer::set_storage(unsigned int aWidth, unsigned int aHeight, color_format aFormat)
{
	assert(is_bound());
	glRenderbufferStorage(GL_RENDERBUFFER, aFormat, aWidth, aHeight);
}

void render_buffer::bind(render_buffer &aRenderBuffer, GLuint aTarget)
{
	glBindRenderbuffer(aTarget, aRenderBuffer.my_buffer);
}

void render_buffer::unbind(render_buffer &aRenderBuffer, GLuint aTarget)
{
	glBindRenderbuffer(aTarget, 0);
}

render_buffer::stack_type &render_buffer::get_states()
{
	return g_states;
}