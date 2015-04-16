#pragma once

namespace ogl
{
	template<class T, typename U = void>
	class bindable
	{
		template<class T, typename U> friend class scoped_binder;
	public:
		typedef U constant_type;
		typedef std::map<U, std::vector<T*>> stack_type;

	public:
		bindable(U aConstant = {}) :
			my_constant(aConstant),
			my_isbound(false),
			my_boundto()
		{

		}

		bindable(bindable &&aMove) :
			my_constant(aMove.my_constant),
			my_isbound(aMove.my_isbound),
			my_boundto(aMove.my_boundto)
		{

		}

		void bind(T &aBindable, U aOverload)
		{
			// Retrieve the appropriate stack of objects/states
			auto &state = T::get_states();
			auto &lookup = state[aOverload];

			// Notify the previous object, should one exist, that it's no longer bound.
			if (!lookup.empty())
				lookup.back()->my_isbound = false;

			// Push our object onto our stack
			lookup.push_back(&aBindable);

			T::bind(aBindable, aOverload);
			my_isbound = true;
			my_boundto = aOverload;
		}

		void bind(T &aBindable)
		{
			bind(aBindable, aBindable.my_constant);
		}

		void unbind(T &aBindable, U aOverload)
		{
			// Retrieve the appropriate stack of objects/states
			auto &state = T::get_states();
			auto &lookup = state[aOverload];

			//assert(my_isbound);

			// Unbind ourselves
			T::unbind(aBindable, aOverload);
			my_isbound = false;
			my_boundto = {};

			// Rebind the new top object
			lookup.pop_back();
			if (!lookup.empty())
			{
				T::bind(*lookup.back(), aOverload);
				lookup.back()->my_isbound = true;
				lookup.back()->my_boundto = aOverload;
			}
		}

		void unbind(T &aBindable)
		{
			unbind(aBindable, aBindable.my_constant);
		}

		bool is_bound() const { return my_isbound; }
		U bound_to() const { return my_boundto; }

	private:
		bindable(const bindable &) = delete;
		bindable &operator=(const bindable &) = delete;

	private:
		const U my_constant;
		U my_boundto;
		bool my_isbound;
	};

	// Specialize for classes with no extra argument
	template<class T>
	class bindable<T, void>
	{
	public:
		typedef void constant_type;
		typedef std::vector<T*> stack_type;

	public:
		bindable() : my_isbound(false)	{}
		bindable(bindable &&aMove) : my_isbound(aMove.my_isbound) {}

		void bind(T &aBindable)
		{
			// Retrieve the stack of objects/states
			auto &lookup = T::get_states();

			// Notify the previous object, should one exist, that it's no longer bound.
			if (!lookup.empty())
				lookup.back()->my_isbound = false;

			// Push our object onto our stack
			lookup.push_back(&aBindable);

			T::bind(aBindable);
			my_isbound = true;
		}

		void unbind(T &aBindable)
		{
			// Retrieve the stack of objects/states
			auto &lookup = T::get_states();

			//assert(my_isbound);

			// Unbind ourselves
			T::unbind(aBindable);
			my_isbound = false;

			// Rebind the new top object
			lookup.pop_back();
			if (!lookup.empty())
			{
				T::bind(*lookup.back());
				lookup.back()->my_isbound = true;
			}
		}

		bool is_bound() const { return my_isbound; }

	private:
		bindable(const bindable &) = delete;
		bindable &operator=(const bindable &) = delete;

	private:
		bool my_isbound;
	};


	template<class T, typename ...Args>
	void bind(T &aBindable, Args... aOverload)
	{
		static_cast<bindable<T, T::constant_type>&>(aBindable).bind(aBindable, aOverload...);
	}

	template<class T>
	typename std::enable_if<std::is_same<typename T::constant_type, void>::value, void>::type bind(T &aBindable)
	{
		static_cast<bindable<T, void>&>(aBindable).bind(aBindable);
	}

	template<class T, typename ...Args>
	void unbind(T &aBindable, Args... aOverload)
	{
		static_cast<bindable<T, T::constant_type>&>(aBindable).unbind(aBindable, aOverload...);
	}

	template<class T>
	typename std::enable_if<std::is_same<typename T::constant_type, void>::value, void>::type unbind(T &aBindable)
	{
		static_cast<bindable<T, void>&>(aBindable).unbind(aBindable);
	}


	template<class T, typename U>
	class scoped_binder : public noncopyable
	{
	public:
		scoped_binder(T &aBindable) :
			my_zombie(false),
			my_bindable(aBindable),
			my_overload(aBindable.my_constant)
		{
			ogl::bind(aBindable, aBindable.my_constant);
		}

		scoped_binder(T &aBindable, U aOverload) :
			my_zombie(false),
			my_bindable(aBindable),
			my_overload(aOverload)
		{
			ogl::bind(aBindable, aOverload);
		}

		~scoped_binder()
		{
			if(!my_zombie)
				ogl::unbind(my_bindable, my_overload);
		}

		scoped_binder(scoped_binder &&aMove) :
			my_bindable(aMove.my_bindable),
			my_overload(aMove.my_overload)
		{
			// Gotta mark it as a zombie, otherwise it'll unbind OUR object when it dies
			aMove.my_zombie = true;

			ogl::bind(my_bindable, my_overload);
		}

		void operator()(std::function<void(void)> aLambda) const
		{
			aLambda();
		}

	private:
		bool my_zombie;
		T &my_bindable;
		typename T::constant_type my_overload;
	};

	template<class T>
	class scoped_binder<T, void> : public noncopyable
	{
	public:
		scoped_binder(T &aBindable) :
			my_zombie(false),
			my_bindable(aBindable)
		{
			ogl::bind(aBindable);
		}

		~scoped_binder()
		{
			if(!my_zombie)
				ogl::unbind(my_bindable);
		}

		scoped_binder(scoped_binder &&aMove) :
			my_bindable(aMove.my_bindable)
		{
			// Gotta mark it as a zombie, otherwise it'll unbind OUR object when it dies
			aMove.my_zombie = true;

			ogl::bind(my_bindable);
		}

		void operator()(std::function<void(void)> aLambda) const
		{
			aLambda();
		}

	private:
		bool my_zombie;
		T &my_bindable;
	};

	template<class T>
	auto scope_bind(T &aBindable, typename T::constant_type aOverload)
	{
		return scoped_binder<T, T::constant_type>(aBindable, aOverload);
	}

	template<class T>
	auto scope_bind(T &aBindable)
	{
		return scoped_binder<T, T::constant_type>(aBindable);
	}
}

