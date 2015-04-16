#pragma once

namespace ogl
{

	class vertex_buffer : public noncopyable, public bindable<vertex_buffer, GLuint>
	{
	public:

		enum target
		{
			array_buffer 				= GL_ARRAY_BUFFER,
			atomic_counter_buffer 		= GL_ATOMIC_COUNTER_BUFFER,
			copy_read_buffer 			= GL_COPY_READ_BUFFER,
			copy_write_buffer 			= GL_COPY_WRITE_BUFFER,
			dispatch_indirect_buffer	= GL_DISPATCH_INDIRECT_BUFFER,
			draw_indirect_buffer 		= GL_DRAW_INDIRECT_BUFFER,
			element_array_buffer 		= GL_ELEMENT_ARRAY_BUFFER,
			pixel_pack_buffer 			= GL_PIXEL_PACK_BUFFER,
			pixel_unpack_buffer 		= GL_PIXEL_UNPACK_BUFFER,
			shader_storage_buffer 		= GL_SHADER_STORAGE_BUFFER,
			texture_buffer 				= GL_TEXTURE_BUFFER,
			transform_feedback_buffer 	= GL_TRANSFORM_FEEDBACK_BUFFER,
			uniform_buffer 				= GL_UNIFORM_BUFFER
		};

		enum usage
		{
			stream_draw = GL_STREAM_DRAW,
			stream_read = GL_STREAM_READ,
			stream_copy = GL_STREAM_COPY,
			static_draw = GL_STATIC_DRAW,
			static_read = GL_STATIC_READ,
			static_copy = GL_STATIC_COPY,
			dynamic_draw = GL_DYNAMIC_DRAW,
			dynamic_read = GL_DYNAMIC_READ,
			dynamic_copy = GL_DYNAMIC_COPY
		};

		enum layout
		{
			interleaved = 0,
			non_interleaved
		};
	public:
		OGLEXPORT vertex_buffer();
		OGLEXPORT ~vertex_buffer();
		OGLEXPORT vertex_buffer(target aTarget);
		OGLEXPORT vertex_buffer(vertex_buffer &&aMove);
		OGLEXPORT operator GLuint();

		OGLEXPORT void set_data(GLint aSize, const void *aData, usage aUsage);
		OGLEXPORT void set_pointer(GLuint aIndex, unsigned int aCount, pixel_format aPixelFormat, bool aNormalized, unsigned int aStride, unsigned int aOffset);

		OGLEXPORT static void bind(vertex_buffer &aBuffer, GLuint aOverload);
		OGLEXPORT static void unbind(vertex_buffer &aBuffer, GLuint aOverload);
		OGLEXPORT static stack_type &get_states();

		template<typename T, int Size>
		void set_data(T(&aVertices)[Size], usage aUsage)
		{
			set_data(sizeof(T) * Size, (const void *)aVertices, aUsage);
		}

		template<typename T>
		void set_data(std::vector<T> aVertices, usage aUsage)
		{
			set_data(sizeof(T) * aVertices.size(), &aVertices[0], aUsage);
		}

		template<typename T>
		void set_data(typename T::const_iterator first, typename T::const_iterator last, usage aUsage)
		{
			set_data(sizeof(T::value_type) * (last - first), &(*first), aUsage);
		}

		
		// This function derives information about the layout of the vertex buffer
		// Example usage:
		//		vbuffer.set_pointer<my_vertex>(0, &my_vertex::x, &my_vertex::y, &my_vertex::z);
		//		vbuffer.set_pointer<my_vertex>(1, &my_vertex::u, &my_vertex::v);
		//
		// For defining an interleaved vertex buffer with 2 attributes, one 3 and one 2 in size, respectively
		template<typename T, layout Layout = interleaved, typename ...Args>
		void set_pointer(GLuint aIndex, Args... args)
		{
			auto bounds = encompass<T>(args...);
			auto count = (bounds.second - bounds.first) / sizeof(decltype(to_member_type(args...)));
			auto format = to_pixel_format<decltype(to_member_type(args...))>();

			set_pointer(aIndex, count, format, GL_FALSE, sizeof(T), (Layout == interleaved) ? bounds.first : 0);
		}

		// As above, but uses an initializer_list instead of a parameter pack, so it can be used at runtime.
		// Note: The members passed in the initializer_list (the second argument) must be sequential.
		// You cannot for example, define a class as vertex {x, y, u, v, z}, and pass the arguments as above
		template<typename T, typename Member = T::point_type, layout Layout = interleaved>
		void set_pointer(GLuint aIndex, std::initializer_list<Member T::*> aMembers)
		{
			auto bounds = encompass<T, Member>(aMembers);
			auto count = (bounds.second - bounds.first) / sizeof(Member);
			auto format = to_pixel_format<Member>();

			set_pointer(aIndex, count, format, GL_FALSE, sizeof(T), (Layout == interleaved) ? bounds.first : 0);
		}

		// Auto-deduce type info for the vertex class and members
		template<typename T, layout Layout = interleaved>
		void set_pointer(GLuint aIndex, std::initializer_list<T> aMembers)
		{
			set_pointer<
				decltype(to_method_class(*aMembers.begin())), 
				decltype(to_member_type(*aMembers.begin())), 
				Layout
			>(aIndex, aMembers);
		}

	private:
		GLuint my_buffer;
	};
}