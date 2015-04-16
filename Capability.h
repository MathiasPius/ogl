#pragma once

namespace ogl
{
	class capability : public noncopyable, public nonassignable, public bindable<capability>
	{
	public:
		OGLEXPORT capability(GLuint aCapability);
		OGLEXPORT ~capability();

		OGLEXPORT operator GLuint() const;

		OGLEXPORT static void bind(const capability &aSlot);
		OGLEXPORT static void unbind(const capability &aSlot);
		OGLEXPORT static stack_type &get_states();

		OGLEXPORT static capability alpha_test;
		OGLEXPORT static capability auto_normal;
		OGLEXPORT static capability blend;
		OGLEXPORT static capability clip_plane0;
		OGLEXPORT static capability clip_plane1;
		OGLEXPORT static capability clip_plane2;
		OGLEXPORT static capability clip_plane3;
		OGLEXPORT static capability clip_plane4;
		OGLEXPORT static capability clip_plane5;
		OGLEXPORT static capability color_logic_op;
		OGLEXPORT static capability color_material;
		OGLEXPORT static capability color_sum;
		OGLEXPORT static capability color_table;
		OGLEXPORT static capability convolution_1d;
		OGLEXPORT static capability convolution_2d;
		OGLEXPORT static capability cull_face;
		OGLEXPORT static capability depth_test;
		OGLEXPORT static capability dither;
		OGLEXPORT static capability fog;
		OGLEXPORT static capability histogram;
		OGLEXPORT static capability index_logic_op;
		OGLEXPORT static capability light0;
		OGLEXPORT static capability light1;
		OGLEXPORT static capability light2;
		OGLEXPORT static capability light3;
		OGLEXPORT static capability light4;
		OGLEXPORT static capability light5;
		OGLEXPORT static capability light6;
		OGLEXPORT static capability light7;
		OGLEXPORT static capability lighting;
		OGLEXPORT static capability line_smooth;
		OGLEXPORT static capability line_stipple;
		OGLEXPORT static capability map1_color_4;
		OGLEXPORT static capability map1_index;
		OGLEXPORT static capability map1_normal;
		OGLEXPORT static capability map1_texture_coord_1;
		OGLEXPORT static capability map1_texture_coord_2;
		OGLEXPORT static capability map1_texture_coord_3;
		OGLEXPORT static capability map1_texture_coord_4;
		OGLEXPORT static capability map1_vertex_3;
		OGLEXPORT static capability map1_vertex_4;
		OGLEXPORT static capability map2_color_4;
		OGLEXPORT static capability map2_index;
		OGLEXPORT static capability map2_normal;
		OGLEXPORT static capability map2_texture_coord_1;
		OGLEXPORT static capability map2_texture_coord_2;
		OGLEXPORT static capability map2_texture_coord_3;
		OGLEXPORT static capability map2_texture_coord_4;
		OGLEXPORT static capability map2_vertex_3;
		OGLEXPORT static capability map2_vertex_4;
		OGLEXPORT static capability minmax;
		OGLEXPORT static capability multisample;
		OGLEXPORT static capability normalize;
		OGLEXPORT static capability point_smooth;
		OGLEXPORT static capability point_sprite;
		OGLEXPORT static capability polygon_offset_fill;
		OGLEXPORT static capability polygon_offset_line;
		OGLEXPORT static capability polygon_offset_point;
		OGLEXPORT static capability polygon_smooth;
		OGLEXPORT static capability polygon_stipple;
		OGLEXPORT static capability post_color_matrix_color_table;
		OGLEXPORT static capability post_convolution_color_table;
		OGLEXPORT static capability rescale_normal;
		OGLEXPORT static capability sample_alpha_to_coverage;
		OGLEXPORT static capability sample_alpha_to_one;
		OGLEXPORT static capability sample_coverage;
		OGLEXPORT static capability separable_2d;
		OGLEXPORT static capability scissor_test;
		OGLEXPORT static capability stencil_test;
		OGLEXPORT static capability texture_1d;
		OGLEXPORT static capability texture_2d;
		OGLEXPORT static capability texture_3d;
		OGLEXPORT static capability texture_cube_map;
		OGLEXPORT static capability texture_gen_q;
		OGLEXPORT static capability texture_gen_r;
		OGLEXPORT static capability texture_gen_s;
		OGLEXPORT static capability texture_gen_t;
		OGLEXPORT static capability vertex_program_point_size;
		OGLEXPORT static capability vertex_program_two_side;

	private:
		GLuint my_capability;
	};
}