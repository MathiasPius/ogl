#pragma once
#include <iostream>

namespace ogl
{
	template<class T>
	void fail(std::string aAssertion, std::string aFilename, unsigned long aLine, const T &aMessage)
	{
		auto last = aFilename.find_last_of("/\\");
		auto filename = (last != std::string::npos) ? aFilename.substr(last + 1) : aFilename;
		std::cerr << 
			"Assertion " << aAssertion << 
			" failed: " << aMessage << 
			" in " << filename << 
			" on line " << aLine << 
			std::endl;
		abort();
	}
}

#ifdef _DEBUG
#define assert(_x_, ...) if(!(_x_)) { ogl::fail(#_x_, __FILE__, __LINE__, ""#__VA_ARGS__); }

#else
#define assert(_x_) ()
#endif