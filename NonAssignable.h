#pragma once

namespace ogl
{
	class nonassignable
	{
	public:
		nonassignable() {}
		~nonassignable() {}

	private:
		nonassignable(const nonassignable &copy) = delete;
		nonassignable(nonassignable &&) = delete;
		nonassignable &operator=(const nonassignable &copy) = delete;
		nonassignable &operator=(nonassignable &&) = delete;
	};
}