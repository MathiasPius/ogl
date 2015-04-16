#pragma once

namespace ogl
{
	enum attachment
	{
		color_attachment0 = GL_COLOR_ATTACHMENT0,
		color_attachment1 = GL_COLOR_ATTACHMENT1,
		color_attachment2 = GL_COLOR_ATTACHMENT2,
		color_attachment3 = GL_COLOR_ATTACHMENT3,
		color_attachment4 = GL_COLOR_ATTACHMENT4,
		color_attachment5 = GL_COLOR_ATTACHMENT5,
		color_attachment6 = GL_COLOR_ATTACHMENT6,
		color_attachment7 = GL_COLOR_ATTACHMENT7,
		color_attachment8 = GL_COLOR_ATTACHMENT8,
		color_attachment9 = GL_COLOR_ATTACHMENT9,
		color_attachment10 = GL_COLOR_ATTACHMENT10,
		color_attachment11 = GL_COLOR_ATTACHMENT11,
		color_attachment12 = GL_COLOR_ATTACHMENT12,
		color_attachment13 = GL_COLOR_ATTACHMENT13,
		color_attachment14 = GL_COLOR_ATTACHMENT14,
		color_attachment15 = GL_COLOR_ATTACHMENT15,
		stencil_attachment = GL_STENCIL_ATTACHMENT,
		depth_attachment = GL_DEPTH_ATTACHMENT
	};

	enum color_format
	{
		// Base Internal Formats
		depth_component = GL_DEPTH_COMPONENT,
		depth_component16 = GL_DEPTH_COMPONENT16,
		depth_component24 = GL_DEPTH_COMPONENT24,
		depth_component32 = GL_DEPTH_COMPONENT32,
		depth_stencil = GL_DEPTH_STENCIL,
		red = GL_RED,
		rg = GL_RG,
		rgb = GL_RGB,
		rgba = GL_RGBA,
		// Sized Internal Formats
		r8 = GL_R8,
		r8_snorm = GL_R8_SNORM,
		r16 = GL_R16,
		r16_snorm = GL_R16_SNORM,
		rg8 = GL_RG8,
		rg8_snorm = GL_RG8_SNORM,
		rg16_snorm = GL_RG16_SNORM,
		r3_g3_b2 = GL_R3_G3_B2,
		rgb4 = GL_RGB4,
		rgb5 = GL_RGB5,
		rgb8 = GL_RGB8,
		rgb8_snorm = GL_RGB8_SNORM,
		rgb10 = GL_RGB10,
		rgb12 = GL_RGB12,
		rgb16_snorm = GL_RGB16_SNORM,
		rgba2 = GL_RGBA2,
		rgba4 = GL_RGBA4,
		rgb5_a1 = GL_RGB5_A1,
		rgba8 = GL_RGBA8,
		rgba8_snorm = GL_RGBA8_SNORM,
		rgb10_a2 = GL_RGB10_A2,
		rgb10_a2ui = GL_RGB10_A2UI,
		rgba12 = GL_RGBA12,
		rgba16 = GL_RGBA16,
		srgb8 = GL_SRGB8,
		srgb8_alpha8 = GL_SRGB8_ALPHA8,
		r16f = GL_R16F,
		rg16f = GL_RG16F,
		rgb16f = GL_RGB16F,
		rgba16f = GL_RGBA16F,
		r32f = GL_R32F,
		rg32f = GL_RG32F,
		rgb32f = GL_RGB32F,
		rgba32f = GL_RGBA32F,
		r11f_g11f_b10f = GL_R11F_G11F_B10F,
		rgb9_e5 = GL_RGB9_E5,
		r8i = GL_R8I,
		r8ui = GL_R8UI,
		r16i = GL_R16I,
		r16ui = GL_R16UI,
		r32i = GL_R32I,
		r32ui = GL_R32UI,
		rg8i = GL_RG8I,
		rg8ui = GL_RG8UI,
		rg16i = GL_RG16I,
		rg16ui = GL_RG16UI,
		rg32i = GL_RG32I,
		rg32ui = GL_RG32UI,
		rgb8i = GL_RGB8I,
		rgb8ui = GL_RGB8UI,
		rgb16i = GL_RGB16I,
		rgb16ui = GL_RGB16UI,
		rgb32i = GL_RGB32I,
		rgb32ui = GL_RGB32UI,
		rgba8i = GL_RGBA8I,
		rgba8ui = GL_RGBA8UI,
		rgba16i = GL_RGBA16I,
		rgba16ui = GL_RGBA16UI,
		rgba32i = GL_RGBA32I,
		rgba32ui = GL_RGBA32UI,
		// Compressed Internal Formats
		compressed_red = GL_COMPRESSED_RED,
		compressed_rg = GL_COMPRESSED_RG,
		compressed_rgb = GL_COMPRESSED_RGB,
		compressed_rgba = GL_COMPRESSED_RGBA,
		compressed_srgb = GL_COMPRESSED_SRGB,
		compressed_srgb_alpha = GL_COMPRESSED_SRGB_ALPHA,
		compressed_signed_red_rgtc1 = GL_COMPRESSED_SIGNED_RED_RGTC1,
		compressed_signed_rg_rgtc2 = GL_COMPRESSED_SIGNED_RG_RGTC2,

		// Should only be used as default argument in functions that can infer the type
		infer_color_format = 0
	};

	enum pixel_format
	{
		unsigned_byte = GL_UNSIGNED_BYTE,
		byte = GL_BYTE,
		unsigned_short = GL_UNSIGNED_SHORT,
		glshort = GL_SHORT,
		unsigned_int = GL_UNSIGNED_INT,
		glint = GL_INT,
		glfloat = GL_FLOAT,
		gldouble = GL_DOUBLE,
		unsigned_byte_3_3_2 = GL_UNSIGNED_BYTE_3_3_2,
		unsigned_byte_2_3_3_rev = GL_UNSIGNED_BYTE_2_3_3_REV,
		unsigned_short_5_6_5 = GL_UNSIGNED_SHORT_5_6_5,
		unsigned_short_5_6_5_rev = GL_UNSIGNED_SHORT_5_6_5_REV,
		unsigned_short_4_4_4_4 = GL_UNSIGNED_SHORT_4_4_4_4,
		unsigned_short_4_4_4_4_rev = GL_UNSIGNED_SHORT_4_4_4_4_REV,
		unsigned_short_5_5_5_1 = GL_UNSIGNED_SHORT_5_5_5_1,
		unsigned_short_1_5_5_5_rev = GL_UNSIGNED_SHORT_1_5_5_5_REV,
		unsigned_int_8_8_8_8 = GL_UNSIGNED_INT_8_8_8_8,
		unsigned_int_8_8_8_8_rev = GL_UNSIGNED_INT_8_8_8_8_REV,
		unsigned_int_10_10_10_2 = GL_UNSIGNED_INT_10_10_10_2,
		unsigned_int_2_10_10_10_rev = GL_UNSIGNED_INT_2_10_10_10_REV,

		// Should only be used as default argument in functions that can infer the type
		infer_pixel_format = 0
	};

	enum primitive
	{
		points = GL_POINTS,
		line_strip = GL_LINE_STRIP,
		line_loop = GL_LINE_LOOP,
		lines = GL_LINES,
		line_strip_adjacency = GL_LINE_STRIP_ADJACENCY,
		lines_adjacency = GL_LINES_ADJACENCY,
		triangle_strip = GL_TRIANGLE_STRIP,
		triangle_fan = GL_TRIANGLE_FAN,
		triangles = GL_TRIANGLES,
		triangle_strip_adjacency = GL_TRIANGLE_STRIP_ADJACENCY,
		triangles_adjacency = GL_TRIANGLES_ADJACENCY,
		quads = GL_QUADS,
	};

	OGLEXPORT int to_primitive_count(primitive aPrimitive, int aVertexCount);

	// Unsure of how to implement these
	//template<> static unsigned int to_primitive_count<line_strip_adjacency>(int aVertexCount) { return aVertexCount; }
	//template<> static unsigned int to_primitive_count<triangle_strip_adjacency>(int aVertexCount) { return aVertexCount; }

	// Convert actual type to OpenGL enum for said type
	template<typename T> static pixel_format to_pixel_format();
	template<> static pixel_format to_pixel_format<GLbyte>()	{ return pixel_format::byte; };
	template<> static pixel_format to_pixel_format<GLubyte>()	{ return pixel_format::unsigned_byte; };
	template<> static pixel_format to_pixel_format<GLshort>()	{ return pixel_format::glshort; };
	template<> static pixel_format to_pixel_format<GLushort>()	{ return pixel_format::unsigned_short; };
	template<> static pixel_format to_pixel_format<GLint>()		{ return pixel_format::glint; };
	template<> static pixel_format to_pixel_format<GLuint>()	{ return pixel_format::unsigned_int; };
	template<> static pixel_format to_pixel_format<GLfloat>()	{ return pixel_format::glfloat; };
	template<> static pixel_format to_pixel_format<GLdouble>()	{ return pixel_format::gldouble; };

	template<typename T, typename ...Args>
	struct first_of
	{
		typedef T type;
	};

	template<typename T, typename C, typename ...Args>
	auto to_method_class(T C::*M, Args ...args) -> C
	{
		return C{};
	}
	template<typename C, typename T, typename ...Args>
	auto to_member_type(const T C::*M, Args... args) -> T
	{
		return T{};
	}
}