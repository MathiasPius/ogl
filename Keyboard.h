#pragma once

namespace ogl
{
	class key
	{
		friend class keyboard;
	private:
		key(WPARAM lParam, LPARAM wParam);

	public:
		OGLEXPORT key();
		OGLEXPORT key(const key &) = default;
		OGLEXPORT key &operator=(const key &) = default;

		OGLEXPORT key(key &&) = default;
		OGLEXPORT key &operator=(key&&) = default;

	public:
		OGLEXPORT unsigned char get_key() const;
		OGLEXPORT unsigned int get_repeat() const;
		OGLEXPORT unsigned char get_scancode() const;
		OGLEXPORT bool is_extended() const;
		OGLEXPORT bool get_previous_state() const;
		OGLEXPORT bool is_down() const;

	private:
		unsigned char my_primary;
		unsigned int my_secondary;
	};

	class keyboard
	{
		friend class window;
	private:
		keyboard();

		void key_down(WPARAM wParam, LPARAM lParam);
		void key_up(WPARAM wParam, LPARAM lParam);
		void clear_events();

	public:
		OGLEXPORT const key &get_key(unsigned char aIdentifier) const;
		OGLEXPORT bool is_down(unsigned char aIdentifier) const;
		OGLEXPORT const std::vector<key> &get_events() const;

	private:
		std::array<key, 256> my_keys;
		std::vector<key> my_events;
	};
}