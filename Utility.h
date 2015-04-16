#pragma once

namespace ogl
{
	GLuint generate(std::function<void(GLuint, GLuint*)> aGeneratorFunction);

	template<typename ...Args> class callable_list;

	template<> class callable_list<>
	{
	public:
		template<typename T>
		void operator()(T) {}
	};

	template<typename T, typename ...Args>
	class callable_list<T, Args...> : public callable_list<Args...>
	{
	public:
		callable_list<T, Args...>(T &aArg, Args&... args) :
			callable_list<Args...>(args...),
			my_arg(aArg)
		{

		}

		template<typename R>
		void operator()(std::function<R(T &)> aLambda)
		{
			ogl::bind(my_arg);
			aLambda(my_arg);
			ogl::unbind(my_arg);
			callable_list<Args...>::operator()(aLambda);
		}

		// Deduce return type from function, and pass it on
		template<typename R>
		void operator()(R aLambda)
		{
			typedef decltype(aLambda(my_arg)) return_type;
			operator()<return_type>(std::function<return_type(T &)>(aLambda));
		}

	private:
		T &my_arg;
	};

	// Creates an object with a single operator() defined which takes a function.
	// The resulting object will, when called, invoke the function on each parameter
	// in turn, binding and unbinding them before each call as it goes.
	template<typename ...Args>
	callable_list<Args...> foreach(Args&... args)
	{
		return callable_list<Args...>(args...);
	}

	// This function is used for getting the bounds of a range of consecutive arguments
	// within a structure
	template<typename T, typename Head>
	std::pair<int, int> encompass(Head T::*M)
	{
		int off = reinterpret_cast<int>(&(((T*)0)->*M));

		// Construct a range of units this should cover based on size of variable
		return std::pair<int, int>(off, off + sizeof(Head));
	}

	template<typename T, typename Head, typename... Args>
	std::pair<int, int> encompass(Head T::*M, Args... args)
	{
		// Get the relative bounds of the member variable
		int lower = reinterpret_cast<int>(&(((T*)0)->*M));
		int upper = lower + sizeof(Head);

		// Evaluate offsets of other members
		std::pair<int, int> offsets = encompass<T>(args...);

		// Make the offsets encompass all variables
		offsets.first = std::min(offsets.first, lower);
		offsets.second = std::max(offsets.second, upper);

		return offsets;
	}

	template<typename T, typename Member>
	std::pair<int, int> encompass(std::vector<Member T::*> members)
	{
		assert(!members.empty());
		int first_offset = reinterpret_cast<int>(&(((T*)0)->*(*members.begin())));

		int lower = first_offset;
		int upper = first_offset + sizeof(Member);

		for (auto &v : members)
		{
			int memb_offset = reinterpret_cast<int>(&(((T*)0)->*v));
			lower = std::min<int>(lower, memb_offset);
			upper = std::max<int>(lower, memb_offset + sizeof(Member));
		}

		return std::pair<int, int>(lower, upper);
	}
}