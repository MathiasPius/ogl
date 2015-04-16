#pragma once

namespace ogl
{
	class noncopyable
	{
	public:
		noncopyable() {}
		~noncopyable() {}

		noncopyable(noncopyable &&) {}
		noncopyable &operator=(noncopyable &&) {}

	private:
		noncopyable(const noncopyable &copy) = delete;
		noncopyable &operator=(const noncopyable &copy) = delete;
	};
}