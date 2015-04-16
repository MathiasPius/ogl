#pragma once

namespace ogl
{
	class texture : public noncopyable, public bindable<texture, GLuint>
	{
		friend class frame_buffer;
	public:
		enum target
		{
			tex1d = GL_TEXTURE_1D,
			proxy_1d = GL_PROXY_TEXTURE_1D,
			tex2d = GL_TEXTURE_2D,
			proxy_2d = GL_PROXY_TEXTURE_2D,
			tex3d = GL_TEXTURE_3D,
			proxy_3d = GL_PROXY_TEXTURE_3D,
			tex1d_array = GL_TEXTURE_1D_ARRAY,
			tex2d_array = GL_TEXTURE_2D_ARRAY,
			rectangle = GL_TEXTURE_RECTANGLE,
			cube_map = GL_TEXTURE_CUBE_MAP,
			cube_map_array = GL_TEXTURE_CUBE_MAP_ARRAY,
			buffer = GL_TEXTURE_BUFFER,
			tex2d_multisample = GL_TEXTURE_2D_MULTISAMPLE,
			tex2d_multisample_array = GL_TEXTURE_2D_MULTISAMPLE_ARRAY
		};

		enum parameter
		{
			depth_stencil_texture_mode = GL_DEPTH_STENCIL_TEXTURE_MODE,
			base_level = GL_TEXTURE_BASE_LEVEL,
			compare_func = GL_TEXTURE_COMPARE_FUNC,
			compare_mode = GL_TEXTURE_COMPARE_MODE,
			lod_bias = GL_TEXTURE_LOD_BIAS,
			min_filter = GL_TEXTURE_MIN_FILTER,
			mag_filter = GL_TEXTURE_MAG_FILTER,
			min_lod = GL_TEXTURE_MIN_LOD,
			max_lod = GL_TEXTURE_MAX_LOD,
			max_level = GL_TEXTURE_MAX_LEVEL,
			swizzle_r = GL_TEXTURE_SWIZZLE_R,
			swizzle_g = GL_TEXTURE_SWIZZLE_G,
			swizzle_b = GL_TEXTURE_SWIZZLE_B,
			swizzle_a = GL_TEXTURE_SWIZZLE_A,
			wrap_s = GL_TEXTURE_WRAP_S,
			wrap_t = GL_TEXTURE_WRAP_T,
			wrap_r = GL_TEXTURE_WRAP_R
		};

	public:
		OGLEXPORT texture(int aWidth, int aHeight, color_format aColorFormat = rgba, pixel_format aPixelFormat = unsigned_byte, color_format aInternalFormat = infer_color_format);
		OGLEXPORT ~texture();
		OGLEXPORT texture(texture &&aMove);
		OGLEXPORT operator GLuint();

		OGLEXPORT void set_data(void *aPixelData, color_format aColorFormat = rgba, pixel_format aPixelFormat = unsigned_byte, int aMipmapLevel = 0);
		OGLEXPORT void set_parameter(parameter aParameter, GLuint aValue);

		OGLEXPORT static void bind(texture &aTexture, GLuint aTarget);
		OGLEXPORT static void unbind(texture &aTexture, GLuint aTarget);
		OGLEXPORT static stack_type &get_states();

	private:
		GLuint my_texture;
	};

	class texture_slot : public bindable<texture_slot, GLuint>
	{
	public:
		OGLEXPORT texture_slot() = default;
		OGLEXPORT texture_slot(GLuint aSlot);
		OGLEXPORT texture_slot(const texture_slot &aSlot);
		OGLEXPORT ~texture_slot();
		
		OGLEXPORT texture_slot &operator=(const texture_slot &aSlot);

		OGLEXPORT operator GLuint() const;

		OGLEXPORT static void bind(const texture_slot &aSlot, GLuint aTarget);
		OGLEXPORT static void unbind(const texture_slot &aSlot, GLuint aTarget);
		OGLEXPORT static stack_type &get_states();

		OGLEXPORT static texture_slot texture0;
		OGLEXPORT static texture_slot texture1;
		OGLEXPORT static texture_slot texture2;
		OGLEXPORT static texture_slot texture3;
		OGLEXPORT static texture_slot texture4;
		OGLEXPORT static texture_slot texture5;
		OGLEXPORT static texture_slot texture6;
		OGLEXPORT static texture_slot texture7;
		OGLEXPORT static texture_slot texture8;
		OGLEXPORT static texture_slot texture9;
		OGLEXPORT static texture_slot texture10;
		OGLEXPORT static texture_slot texture11;
		OGLEXPORT static texture_slot texture12;
		OGLEXPORT static texture_slot texture13;
		OGLEXPORT static texture_slot texture14;
		OGLEXPORT static texture_slot texture15;
		OGLEXPORT static texture_slot texture16;
		OGLEXPORT static texture_slot texture17;
		OGLEXPORT static texture_slot texture18;
		OGLEXPORT static texture_slot texture19;
		OGLEXPORT static texture_slot texture20;
		OGLEXPORT static texture_slot texture21;
		OGLEXPORT static texture_slot texture22;
		OGLEXPORT static texture_slot texture23;
		OGLEXPORT static texture_slot texture24;
		OGLEXPORT static texture_slot texture25;
		OGLEXPORT static texture_slot texture26;
		OGLEXPORT static texture_slot texture27;
		OGLEXPORT static texture_slot texture28;
		OGLEXPORT static texture_slot texture29;
		OGLEXPORT static texture_slot texture30;
		OGLEXPORT static texture_slot texture31;

	private:
		GLuint my_slot;
	};
}