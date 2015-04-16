#pragma once

namespace ogl
{
	class render_buffer;
	class texture;

	class frame_buffer : public noncopyable, public bindable<frame_buffer, GLuint>
	{
	public:
		enum status
		{
			complete = GL_FRAMEBUFFER_COMPLETE,
			incomplete_attachment = GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT,
			incomplete_dimensions = GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT,
			incomplete_missing_attachment = GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT,
			unsupported = GL_FRAMEBUFFER_UNSUPPORTED
		};

	public:
		OGLEXPORT frame_buffer();
		OGLEXPORT ~frame_buffer();
		OGLEXPORT frame_buffer(frame_buffer &&aMove);
		OGLEXPORT operator GLuint();

		OGLEXPORT void attach(render_buffer &aRenderBuffer, attachment aAttachment);
		OGLEXPORT void set_texture(texture &aTexture, attachment aAttachment);
		OGLEXPORT void draw_buffers(const std::initializer_list<attachment> &aAttachments);

		OGLEXPORT status get_status() const;

		OGLEXPORT static void bind(frame_buffer &aFrameBuffer, GLuint aTarget);
		OGLEXPORT static void unbind(frame_buffer &aFrameBuffer, GLuint aTarget);
		OGLEXPORT static stack_type &get_states();

	private:
		frame_buffer(const frame_buffer&) = delete;
		GLuint my_buffer;
	};
}