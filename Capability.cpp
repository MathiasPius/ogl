#include "Precompiled.h"
#include "Capability.h"

using namespace ogl;

static capability::stack_type g_states;

capability::capability(GLuint aCapability) :
bindable{},
my_capability(aCapability)
{

}

capability::~capability()
{

}

capability::operator GLuint() const
{
	return my_capability;
}

void capability::bind(const capability &aCapability)
{
	glEnable(aCapability.my_capability);
}

void capability::unbind(const capability &aCapability)
{
	glDisable(aCapability.my_capability);
}

capability::stack_type &capability::get_states()
{
	return g_states;
}

capability ogl::capability::alpha_test{ GL_ALPHA_TEST };
capability ogl::capability::auto_normal{ GL_AUTO_NORMAL };
capability ogl::capability::blend{ GL_BLEND };
capability ogl::capability::clip_plane0{ GL_CLIP_PLANE0 };
capability ogl::capability::clip_plane1{ GL_CLIP_PLANE1 };
capability ogl::capability::clip_plane2{ GL_CLIP_PLANE2 };
capability ogl::capability::clip_plane3{ GL_CLIP_PLANE3 };
capability ogl::capability::clip_plane4{ GL_CLIP_PLANE4 };
capability ogl::capability::clip_plane5{ GL_CLIP_PLANE5 };
capability ogl::capability::color_logic_op{ GL_COLOR_LOGIC_OP };
capability ogl::capability::color_material{ GL_COLOR_MATERIAL };
capability ogl::capability::color_sum{ GL_COLOR_SUM };
capability ogl::capability::color_table{ GL_COLOR_TABLE };
capability ogl::capability::convolution_1d{ GL_CONVOLUTION_1D };
capability ogl::capability::convolution_2d{ GL_CONVOLUTION_2D };
capability ogl::capability::cull_face{ GL_CULL_FACE };
capability ogl::capability::depth_test{ GL_DEPTH_TEST };
capability ogl::capability::dither{ GL_DITHER };
capability ogl::capability::fog{ GL_FOG };
capability ogl::capability::histogram{ GL_HISTOGRAM };
capability ogl::capability::index_logic_op{ GL_INDEX_LOGIC_OP };
capability ogl::capability::light0{ GL_LIGHT0 };
capability ogl::capability::light1{ GL_LIGHT1 };
capability ogl::capability::light2{ GL_LIGHT2 };
capability ogl::capability::light3{ GL_LIGHT3 };
capability ogl::capability::light4{ GL_LIGHT4 };
capability ogl::capability::light5{ GL_LIGHT5 };
capability ogl::capability::light6{ GL_LIGHT6 };
capability ogl::capability::light7{ GL_LIGHT7 };
capability ogl::capability::lighting{ GL_LIGHTING };
capability ogl::capability::line_smooth{ GL_LINE_SMOOTH };
capability ogl::capability::line_stipple{ GL_LINE_STIPPLE };
capability ogl::capability::map1_color_4{ GL_MAP1_COLOR_4 };
capability ogl::capability::map1_index{ GL_MAP1_INDEX };
capability ogl::capability::map1_normal{ GL_MAP1_NORMAL };
capability ogl::capability::map1_texture_coord_1{ GL_MAP1_TEXTURE_COORD_1 };
capability ogl::capability::map1_texture_coord_2{ GL_MAP1_TEXTURE_COORD_2 };
capability ogl::capability::map1_texture_coord_3{ GL_MAP1_TEXTURE_COORD_3 };
capability ogl::capability::map1_texture_coord_4{ GL_MAP1_TEXTURE_COORD_4 };
capability ogl::capability::map1_vertex_3{ GL_MAP1_VERTEX_3 };
capability ogl::capability::map1_vertex_4{ GL_MAP1_VERTEX_4 };
capability ogl::capability::map2_color_4{ GL_MAP2_COLOR_4 };
capability ogl::capability::map2_index{ GL_MAP2_INDEX };
capability ogl::capability::map2_normal{ GL_MAP2_NORMAL };
capability ogl::capability::map2_texture_coord_1{ GL_MAP2_TEXTURE_COORD_1 };
capability ogl::capability::map2_texture_coord_2{ GL_MAP2_TEXTURE_COORD_2 };
capability ogl::capability::map2_texture_coord_3{ GL_MAP2_TEXTURE_COORD_3 };
capability ogl::capability::map2_texture_coord_4{ GL_MAP2_TEXTURE_COORD_4 };
capability ogl::capability::map2_vertex_3{ GL_MAP2_VERTEX_3 };
capability ogl::capability::map2_vertex_4{ GL_MAP2_VERTEX_4 };
capability ogl::capability::minmax{ GL_MINMAX };
capability ogl::capability::multisample{ GL_MULTISAMPLE };
capability ogl::capability::normalize{ GL_NORMALIZE };
capability ogl::capability::point_smooth{ GL_POINT_SMOOTH };
capability ogl::capability::point_sprite{ GL_POINT_SPRITE };
capability ogl::capability::polygon_offset_fill{ GL_POLYGON_OFFSET_FILL };
capability ogl::capability::polygon_offset_line{ GL_POLYGON_OFFSET_LINE };
capability ogl::capability::polygon_offset_point{ GL_POLYGON_OFFSET_POINT };
capability ogl::capability::polygon_smooth{ GL_POLYGON_SMOOTH };
capability ogl::capability::polygon_stipple{ GL_POLYGON_STIPPLE };
capability ogl::capability::post_color_matrix_color_table{ GL_POST_COLOR_MATRIX_COLOR_TABLE };
capability ogl::capability::post_convolution_color_table{ GL_POST_CONVOLUTION_COLOR_TABLE };
capability ogl::capability::rescale_normal{ GL_RESCALE_NORMAL };
capability ogl::capability::sample_alpha_to_coverage{ GL_SAMPLE_ALPHA_TO_COVERAGE };
capability ogl::capability::sample_alpha_to_one{ GL_SAMPLE_ALPHA_TO_ONE };
capability ogl::capability::sample_coverage{ GL_SAMPLE_COVERAGE };
capability ogl::capability::separable_2d{ GL_SEPARABLE_2D };
capability ogl::capability::scissor_test{ GL_SCISSOR_TEST };
capability ogl::capability::stencil_test{ GL_STENCIL_TEST };
capability ogl::capability::texture_1d{ GL_TEXTURE_1D };
capability ogl::capability::texture_2d{ GL_TEXTURE_2D };
capability ogl::capability::texture_3d{ GL_TEXTURE_3D };
capability ogl::capability::texture_cube_map{ GL_TEXTURE_CUBE_MAP };
capability ogl::capability::texture_gen_q{ GL_TEXTURE_GEN_Q };
capability ogl::capability::texture_gen_r{ GL_TEXTURE_GEN_R };
capability ogl::capability::texture_gen_s{ GL_TEXTURE_GEN_S };
capability ogl::capability::texture_gen_t{ GL_TEXTURE_GEN_T };
capability ogl::capability::vertex_program_point_size{ GL_VERTEX_PROGRAM_POINT_SIZE };
capability ogl::capability::vertex_program_two_side{ GL_VERTEX_PROGRAM_TWO_SIDE };