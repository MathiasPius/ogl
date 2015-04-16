#include "Precompiled.h"
#include "Texture.h"

using namespace ogl;

static texture_slot::stack_type g_states;

texture_slot::texture_slot(GLuint aSlot) :
bindable(GL_ACTIVE_TEXTURE),
my_slot(aSlot)
{

}

texture_slot::texture_slot(const texture_slot &aSlot) :
bindable(GL_ACTIVE_TEXTURE),
my_slot(aSlot)
{

}

texture_slot::~texture_slot()
{

}

texture_slot &texture_slot::operator=(const texture_slot &aSlot)
{
	my_slot = aSlot.my_slot;
	return *this;
}

texture_slot::operator GLuint() const
{
	return my_slot;
}

void texture_slot::bind(const texture_slot &aSlot, GLuint aTarget)
{
	glActiveTexture(aSlot.my_slot);
}

void texture_slot::unbind(const texture_slot &aSlot, GLuint aTarget)
{
	glActiveTexture(GL_TEXTURE0);
}

texture_slot::stack_type &texture_slot::get_states()
{
	return g_states;
}

texture_slot ogl::texture_slot::texture0{ GL_TEXTURE0 };
texture_slot ogl::texture_slot::texture1{ GL_TEXTURE1 };
texture_slot ogl::texture_slot::texture2{ GL_TEXTURE2 };
texture_slot ogl::texture_slot::texture3{ GL_TEXTURE3 };
texture_slot ogl::texture_slot::texture4{ GL_TEXTURE4 };
texture_slot ogl::texture_slot::texture5{ GL_TEXTURE5 };
texture_slot ogl::texture_slot::texture6{ GL_TEXTURE6 };
texture_slot ogl::texture_slot::texture7{ GL_TEXTURE7 };
texture_slot ogl::texture_slot::texture8{ GL_TEXTURE8 };
texture_slot ogl::texture_slot::texture9{ GL_TEXTURE9 };
texture_slot ogl::texture_slot::texture10{ GL_TEXTURE10 };
texture_slot ogl::texture_slot::texture11{ GL_TEXTURE11 };
texture_slot ogl::texture_slot::texture12{ GL_TEXTURE12 };
texture_slot ogl::texture_slot::texture13{ GL_TEXTURE13 };
texture_slot ogl::texture_slot::texture14{ GL_TEXTURE14 };
texture_slot ogl::texture_slot::texture15{ GL_TEXTURE15 };
texture_slot ogl::texture_slot::texture16{ GL_TEXTURE16 };
texture_slot ogl::texture_slot::texture17{ GL_TEXTURE17 };
texture_slot ogl::texture_slot::texture18{ GL_TEXTURE18 };
texture_slot ogl::texture_slot::texture19{ GL_TEXTURE19 };
texture_slot ogl::texture_slot::texture20{ GL_TEXTURE20 };
texture_slot ogl::texture_slot::texture21{ GL_TEXTURE21 };
texture_slot ogl::texture_slot::texture22{ GL_TEXTURE22 };
texture_slot ogl::texture_slot::texture23{ GL_TEXTURE23 };
texture_slot ogl::texture_slot::texture24{ GL_TEXTURE24 };
texture_slot ogl::texture_slot::texture25{ GL_TEXTURE25 };
texture_slot ogl::texture_slot::texture26{ GL_TEXTURE26 };
texture_slot ogl::texture_slot::texture27{ GL_TEXTURE27 };
texture_slot ogl::texture_slot::texture28{ GL_TEXTURE28 };
texture_slot ogl::texture_slot::texture29{ GL_TEXTURE29 };
texture_slot ogl::texture_slot::texture30{ GL_TEXTURE30 };
texture_slot ogl::texture_slot::texture31{ GL_TEXTURE31 };