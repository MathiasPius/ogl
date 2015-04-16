#pragma once

namespace ogl
{
	class window;

	class context : public noncopyable, public bindable<context, HDC>
	{
	public:
		enum flags
		{
			unknown = 0,
			forward_compatibility = 1,
			debug = 2,
			core = 4,
			compatibility = 8,
			temporary = 16,

			default = compatibility
		};

		class settings
		{
		public:
			OGLEXPORT settings(
				flags aFlags = default,
				unsigned int aColorBits = 32,
				unsigned int aDepthBits = 24,
				unsigned int aMajorVersion = 3,
				unsigned int aMinorVersion = 2
			);

			OGLEXPORT ~settings();

			flags get_flags() const { return my_flags; }
			unsigned int get_colorbits() const { return my_colorbits; }
			unsigned int get_depthbits() const { return my_depthbits; }
			unsigned int get_major_version() const { return my_majorversion; }
			unsigned int get_minor_version() const { return my_minorversion; }

		private:
			flags my_flags;
			unsigned int my_colorbits;
			unsigned int my_depthbits;
			unsigned int my_majorversion;
			unsigned int my_minorversion;
		};

		class attributes
		{
			friend class context;
		public:
			attributes();
			~attributes();

			void add(int aVariable, int aValue);

		private:
			const int *get() const;

		private:
			std::vector<int> my_attributes;
		};

		struct version_number
		{
			int my_major;
			int my_minor;
		};

	public:
		OGLEXPORT context(const window &aWindow, const settings &aSettings = settings());
		OGLEXPORT ~context();

		OGLEXPORT context(context &&aMove);

		OGLEXPORT version_number get_version() const;

		OGLEXPORT unsigned int get_width() const;
		OGLEXPORT unsigned int get_height() const;

		OGLEXPORT static void bind(context &aContext, HDC aDC);
		OGLEXPORT static void unbind(context &aContext, HDC aDC);
		OGLEXPORT static stack_type &get_states();

	private:
		HDC my_device;
		HGLRC my_context;
	};

	OGLEXPORT std::ostream &operator<<(std::ostream &stream, context::version_number version);
}