#pragma once

namespace ogl
{
	class render_buffer : public noncopyable, public bindable<render_buffer, GLuint>
	{
		friend class frame_buffer;
	public:
		OGLEXPORT render_buffer();
		OGLEXPORT ~render_buffer();

		OGLEXPORT void set_storage(unsigned int aWidth, unsigned int aHeight, color_format aColorFormat = rgba);

		OGLEXPORT static void bind(render_buffer &aRenderBuffer, GLuint aTarget);
		OGLEXPORT static void unbind(render_buffer &aRenderBuffer, GLuint aTarget);
		OGLEXPORT static stack_type &get_states();

	private:
		GLuint my_buffer;
	};
}