#include "Precompiled.h"
#include "Window.h"

using namespace ogl;

window::winclass::winclass(HINSTANCE aModuleHandle) :
	my_modulehandle(aModuleHandle)
{
	WNDCLASSW windowClass;
	windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	windowClass.lpfnWndProc = window::process;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = aModuleHandle;
	windowClass.hIcon = LoadIcon(0, IDI_WINLOGO);
	windowClass.hCursor = LoadCursor(0, IDC_ARROW);
	windowClass.hbrBackground = 0;
	windowClass.lpszMenuName = 0;
	windowClass.lpszClassName = L"OGLWindow";

	RegisterClassW(&windowClass);
}

window::winclass::~winclass()
{
	UnregisterClassW(L"OGlWindow", my_modulehandle);
}