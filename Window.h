#pragma once
#include "Keyboard.h"

namespace ogl
{
	class keyboard;

	class window : public noncopyable
	{
		friend class context;
	public:
		class winclass : public noncopyable
		{
			friend class window;
		public:
			OGLEXPORT winclass(HINSTANCE aModuleHandle = GetModuleHandle(nullptr));
			OGLEXPORT ~winclass();

		private:
			HINSTANCE my_modulehandle;
		};

		class settings
		{
		public:
			OGLEXPORT settings(
				const std::wstring &aTitle = L"OGLWindow",
				unsigned int aWidth = 800,
				unsigned int aHeight = 600
			);
			OGLEXPORT ~settings();

			const std::wstring &get_title() const { return my_title; }
			unsigned int get_width() const { return my_width; }
			unsigned int get_height() const { return my_height; }

		private:
			std::wstring my_title;
			unsigned int my_width;
			unsigned int my_height;
		};

	public:
		OGLEXPORT window(const settings &aSettings = settings());
		OGLEXPORT ~window();

		OGLEXPORT window(window &&aMove);

		OGLEXPORT keyboard &get_keyboard();

		OGLEXPORT void poll();
		OGLEXPORT void draw() const;

	private:
		OGLEXPORT static LRESULT CALLBACK process(HWND aHandle, UINT aMessage, WPARAM wParam, LPARAM lParam);

	private:
		keyboard my_keyboard;
		HWND my_windowhandle;
	};
}