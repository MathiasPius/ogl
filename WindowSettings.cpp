#include "Precompiled.h"
#include "Window.h"

using namespace ogl;

window::settings::settings(const std::wstring &aTitle /* = L"OGLWindow" */, unsigned int aWidth /* = 800 */, unsigned int aHeight /* = 600 */) :
my_title(aTitle),
my_width(aWidth),
my_height(aHeight)
{

}

window::settings::~settings()
{

}