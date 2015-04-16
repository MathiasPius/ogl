#include "Precompiled.h"
#include "Bindable.h"
#include "Utility.h"
#include "Texture.h"

using namespace ogl;

static texture::stack_type g_states;

texture::texture(int aWidth, int aHeight, color_format aColorFormat, pixel_format aPixelFormat, color_format aInternalFormat) :
bindable(GL_TEXTURE_2D),
my_texture(generate(glGenTextures))
{
	auto internal = (aInternalFormat == infer_color_format) ? aColorFormat : aInternalFormat;

	ogl::bind(*this);
	// Create a proxy texture
	glTexImage2D(GL_TEXTURE_2D, 0, internal, aWidth, aHeight, 0, aColorFormat, aPixelFormat, nullptr);
	ogl::unbind(*this);
}

texture::~texture()
{
	if (my_texture)
		glDeleteTextures(1, &my_texture);
}

texture::texture(texture &&aMove) :
bindable(std::forward<bindable>(aMove)),
my_texture(aMove.my_texture)
{
	aMove.my_texture = 0; 
}

texture::operator GLuint()
{
	return my_texture;
}

void texture::set_data(void *aPixelData, color_format aColorFormat, pixel_format aPixelFormat, int aMipmapLevel)
{
	assert(is_bound());

	GLint width = 0;
	GLint height = 0;
	GLint internalFormat = 0;
	GLint colorFormat = aColorFormat;

	// Retrieve the parameters from our proxy texture
	glGetTexLevelParameteriv(bound_to(), aMipmapLevel, GL_TEXTURE_WIDTH, &width);
	glGetTexLevelParameteriv(bound_to(), aMipmapLevel, GL_TEXTURE_HEIGHT, &height);
	glGetTexLevelParameteriv(bound_to(), aMipmapLevel, GL_TEXTURE_INTERNAL_FORMAT, &internalFormat);

	// Apply our new data
	glTexImage2D(GL_TEXTURE_2D, aMipmapLevel, internalFormat, width, height, 0, aColorFormat, aPixelFormat, aPixelData);
}

void texture::set_parameter(parameter aParameter, GLuint aValue)
{
	glTexParameteri(bound_to(), aParameter, aValue);
}

void texture::bind(texture &aTexture, GLuint aTarget)
{
	glBindTexture(aTarget, aTexture.my_texture);
}

void texture::unbind(texture &aTexture, GLuint aTarget)
{
	glBindTexture(aTarget, 0);
}

texture::stack_type &texture::get_states()
{
	return g_states;
}