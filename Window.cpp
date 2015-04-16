#include "Precompiled.h"
#include "Window.h"

using namespace ogl;

static const window::winclass ourWindowClass;

window::window(const settings &aSettings) :
my_windowhandle(nullptr),
my_keyboard()
{
	my_windowhandle = CreateWindowExW(
		WS_EX_APPWINDOW | WS_EX_WINDOWEDGE,
		L"OGLWindow",
		aSettings.get_title().c_str(),
		WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
		0, 0, aSettings.get_width(), aSettings.get_height(), 0, 0,
		ourWindowClass.my_modulehandle,
		nullptr
	);

	SetWindowLongPtr(my_windowhandle, GWL_USERDATA, (LONG)this);

	ShowWindow(my_windowhandle, SW_SHOW);
}

window::~window()
{
	if (my_windowhandle)
		CloseWindow(my_windowhandle);
}

window::window(window &&aMove) :
my_windowhandle(aMove.my_windowhandle)
{
	aMove.my_windowhandle = nullptr;
}

keyboard &window::get_keyboard()
{
	return my_keyboard;
}

void window::poll()
{
	my_keyboard.clear_events();
	MSG msg;
	while (PeekMessage(&msg, my_windowhandle, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

void window::draw() const
{
	auto dc = GetDC(my_windowhandle);
	SwapBuffers(dc);
	ReleaseDC(my_windowhandle, dc);
}