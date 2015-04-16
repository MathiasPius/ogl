#include "Precompiled.h"
#include "Keyboard.h"

using namespace ogl;

key::key() :
	my_primary(0),
	my_secondary(0)
{

}

key::key(WPARAM wParam, LPARAM lParam) :
	my_primary((unsigned char)wParam),
	my_secondary(lParam)
{

}

unsigned char key::get_key() const
{
	return my_primary;
}

unsigned int key::get_repeat() const
{
	return my_secondary & (USHRT_MAX);
}

unsigned char key::get_scancode() const
{
	return ((char *)&my_secondary)[2];
}

bool key::is_extended() const
{
	return (my_secondary & (unsigned int)16777216) > 0;
}

bool key::get_previous_state() const
{
	return (my_secondary & (unsigned int)1073741824) > 0;
}

bool key::is_down() const
{
	return (my_secondary & (unsigned int)2147483648) == 0;
}