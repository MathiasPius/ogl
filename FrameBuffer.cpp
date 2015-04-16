#include "Precompiled.h"
#include "FrameBuffer.h"
#include "Bindable.h"
#include "RenderBuffer.h"
#include "Texture.h"
#include "Utility.h"

using namespace ogl;

static frame_buffer::stack_type g_states;

frame_buffer::frame_buffer() :
bindable(GL_FRAMEBUFFER),
my_buffer(generate(glGenFramebuffers))
{

}

frame_buffer::~frame_buffer()
{

}

frame_buffer::frame_buffer(frame_buffer &&aMove) :
bindable(std::forward<bindable>(aMove)),
my_buffer(aMove.my_buffer)
{
	aMove.my_buffer = 0;
}

frame_buffer::operator GLuint()
{
	return my_buffer;
}

void frame_buffer::attach(render_buffer &aRenderBuffer, attachment aAttachment)
{
	assert(is_bound());
	assert(aRenderBuffer.is_bound());

	glFramebufferRenderbuffer(bound_to(), aAttachment, aRenderBuffer.bound_to(), aRenderBuffer.my_buffer);
}

void frame_buffer::set_texture(texture &aTexture, attachment aAttachment)
{
	assert(is_bound());
	assert(aTexture.is_bound());

	glFramebufferTexture2D(bound_to(), aAttachment, aTexture.bound_to(), aTexture.my_texture, 0);
}

void frame_buffer::draw_buffers(const std::initializer_list<attachment> &aAttachments)
{
	glDrawBuffers(aAttachments.size(), reinterpret_cast<const GLenum *>(aAttachments.begin()));
}

frame_buffer::status frame_buffer::get_status() const
{
	assert(is_bound());

	return static_cast<status>(glCheckFramebufferStatus(bound_to()));
}

void frame_buffer::bind(frame_buffer &aFrameBuffer, GLuint aTarget)
{
	glBindFramebuffer(aTarget, aFrameBuffer.my_buffer);
}

void frame_buffer::unbind(frame_buffer &aFrameBuffer, GLuint aTarget)
{
	glBindFramebuffer(aTarget, 0);
}

frame_buffer::stack_type &frame_buffer::get_states()
{
	return g_states;
}