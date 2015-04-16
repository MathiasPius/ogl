#include "Precompiled.h"
#include "Window.h"
#include "Keyboard.h"

using namespace ogl;

LRESULT CALLBACK window::process(HWND aHandle, UINT aMessage, WPARAM wParam, LPARAM lParam)
{
	auto wind = reinterpret_cast<window *>(GetWindowLongPtr(aHandle, GWL_USERDATA));

	if(wind == nullptr || wind->my_windowhandle != aHandle)
		return DefWindowProc(aHandle, aMessage, wParam, lParam);

	switch (aMessage)
	{
	case WM_KEYDOWN:
	{
		wind->get_keyboard().key_down(wParam, lParam);
		break;
	}

	case WM_KEYUP:
	{
		wind->get_keyboard().key_up(wParam, lParam);
		break;
	}

	default: break;
	}

	return DefWindowProc(aHandle, aMessage, wParam, lParam);
}