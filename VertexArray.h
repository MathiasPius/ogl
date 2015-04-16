#pragma once

namespace ogl
{
	class vertex_array : public noncopyable, public bindable<vertex_array, GLuint>
	{
	public:
		OGLEXPORT vertex_array();
		OGLEXPORT ~vertex_array();
		OGLEXPORT vertex_array(vertex_array &&arr);
		OGLEXPORT operator GLuint();

		OGLEXPORT void enable_array(GLuint aIndex);
		OGLEXPORT void enable_arrays(std::vector<GLuint> aIndices);

		OGLEXPORT static void bind(vertex_array &aBuffer, GLuint aOverload);
		OGLEXPORT static void unbind(vertex_array &aBuffer, GLuint aOverload);
		OGLEXPORT static stack_type &get_states();

	private:
		GLuint my_buffer;
	};
}