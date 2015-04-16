#include "Precompiled.h"
#include "Keyboard.h"

using namespace ogl;

keyboard::keyboard() :
	my_keys()
{
	for (unsigned int i = 0; i < 256; i++)
	{
		my_keys[i] = key(i, 0);
	}
}

void keyboard::key_down(WPARAM wParam, LPARAM lParam)
{
	my_keys[(unsigned char)wParam] = key(wParam, lParam);
	my_events.emplace_back(key(wParam, lParam));
}

void keyboard::key_up(WPARAM wParam, LPARAM lParam)
{
	my_keys[(unsigned char)wParam] = key(wParam, lParam);
	my_events.emplace_back(key(wParam, lParam));
}

void keyboard::clear_events()
{
	my_events.clear();
}

const key &keyboard::get_key(unsigned char aIdentifier) const
{
	return my_keys[aIdentifier];
}

bool keyboard::is_down(unsigned char aIdentifier) const
{
	return my_keys[aIdentifier].is_down();
}

const std::vector<key> &keyboard::get_events() const
{
	return my_events;
}
