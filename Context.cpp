#include "Precompiled.h"
#include "Context.h"
#include "Window.h"
#include "Bindable.h"

using namespace ogl;

static context::stack_type g_states;

context::context(const window &aWindow, const settings &aSettings /* = settings() */) :
bindable(GetDC(aWindow.my_windowhandle)),
my_device(nullptr),
my_context(nullptr)
{
	HDC device = GetDC(aWindow.my_windowhandle);

	// Pixel format
	static PIXELFORMATDESCRIPTOR pfd;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = aSettings.get_colorbits();
	pfd.cDepthBits = aSettings.get_depthbits();
	pfd.iLayerType = PFD_MAIN_PLANE;

	int first = ChoosePixelFormat(device, &pfd);
	SetPixelFormat(device, first, &pfd);

	// Dummy context
	HGLRC tempContext = wglCreateContext(device);
	wglMakeCurrent(device, tempContext);
		
	glewExperimental = GL_TRUE;
	glewInit();

	// Flag translation
	if ((aSettings.get_flags() & context::temporary) || wglewIsSupported("WGL_ARB_create_context") != 1)
	{
		my_device = device;
		my_context = wglCreateContext(device);
		return;
	}

	attributes attrib;
	attrib.add(WGL_CONTEXT_MAJOR_VERSION_ARB, aSettings.get_major_version());
	attrib.add(WGL_CONTEXT_MINOR_VERSION_ARB, aSettings.get_minor_version());

	attrib.add(WGL_CONTEXT_FLAGS_ARB,
		((aSettings.get_flags() & forward_compatibility) ? WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB : 0) |
		((aSettings.get_flags() & debug) ? WGL_CONTEXT_DEBUG_BIT_ARB : 0)
	);

	if ((aSettings.get_major_version() == 3 && aSettings.get_minor_version() >= 2) || aSettings.get_major_version() > 3)
	{
		attrib.add(WGL_CONTEXT_PROFILE_MASK_ARB,
			((aSettings.get_flags() & core) ? WGL_CONTEXT_CORE_PROFILE_BIT_ARB : 0) |
			((aSettings.get_flags() & compatibility) ? WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB : 0)
		);
	}

	// Create our real context
	if (my_context = wglCreateContextAttribsARB(device, 0, attrib.get()))
		my_device = device;

	// Destroy the temporary context
	wglMakeCurrent(device, nullptr);
	wglDeleteContext(tempContext);

	// Initialize glew in the new context
	wglMakeCurrent(my_device, my_context);
	glewInit();
	wglMakeCurrent(my_device, nullptr);
}

context::~context()
{
	wglDeleteContext(my_context);
}

context::context(context &&aMove) :
bindable(std::forward<bindable>(aMove)),
my_context(aMove.my_context),
my_device(aMove.my_device)
{
	aMove.my_device = nullptr;
	aMove.my_context = nullptr;
}

context::version_number context::get_version() const
{
	int majorVersion = 0;
	int minorVersion = 0;
	const char *version = (const char *)glGetString(GL_VERSION);

	if (version[0] - '0' >= 3)
	{
		glGetIntegerv(GL_MAJOR_VERSION, &majorVersion);
		glGetIntegerv(GL_MAJOR_VERSION, &minorVersion);
	}
	else
	{
		majorVersion = version[0] - '0';
		minorVersion = version[1] - '0';
	}

	return{ majorVersion, minorVersion };
}

unsigned int context::get_width() const
{
	HWND handle = WindowFromDC(my_device);

	RECT rect;
	GetClientRect(handle, &rect);

	return rect.right - rect.left;
}

unsigned int context::get_height() const
{
	HWND handle = WindowFromDC(my_device);

	RECT rect;
	GetClientRect(handle, &rect);

	return rect.bottom - rect.top;
}

void context::bind(context &aContext, HDC aDevice)
{
	assert(aContext.my_device == aDevice, "Mismatched context device pair when binding");
	wglMakeCurrent(aDevice, aContext.my_context);
	glewInit();
	
}

void context::unbind(context &aContext, HDC aDevice)
{
	assert(aContext.my_device == aDevice, "Mismatched context device pair when unbinding");
	wglMakeCurrent(aDevice, nullptr);
}

context::stack_type &context::get_states()
{
	return g_states;
}

std::ostream &ogl::operator<<(std::ostream &stream, context::version_number version)
{
	return stream << version.my_major << "." << version.my_minor;
}