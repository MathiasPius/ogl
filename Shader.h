#pragma once

namespace ogl
{
	class shader : public noncopyable
	{
		friend class program;
	public:
		enum type
		{
			compute_shader = GL_COMPUTE_SHADER,
			vertex_shader = GL_VERTEX_SHADER,
			tess_control_shader = GL_TESS_CONTROL_SHADER,
			tess_evaluation_shader = GL_TESS_EVALUATION_SHADER,
			geometry_shader = GL_GEOMETRY_SHADER,
			fragment_shader = GL_FRAGMENT_SHADER
		};

	public:
		OGLEXPORT shader(type aShaderType);
		OGLEXPORT shader(shader &&aMove);
		OGLEXPORT ~shader();

		OGLEXPORT void source(std::istream &aStream);
		OGLEXPORT bool compile();

	private:
		GLuint my_shader;
	};

	class program : public noncopyable, public bindable<program, GLuint>
	{
		// This class requires some explanation
		// It's used as a means of using the glUniform functions, and its primary method is "set"
		// set will attempt to deduce the correct glUniform code based on the objects passed to it.
		// Some special cases exist for matrices, as they will have to be passed as float-arrays,
		// and thus fall within the glUniformNfv functions. 
		// For this reason, set has a slightly different definition which takes a Column and Row
		// template argument, specifying the matrix size. If this is defined, then the parameters
		// will use glUniformMatrix* functions instead of the float-vector ones.
	public:
		struct uniform : public noncopyable, public nonassignable
		{
		private:
			template<typename ...Args>
			auto get_uniform_function(Args... aArgs) 
			{
				assert(false, "Uniform function signature does not match any glUniform* function");
				return std::function<void(GLint, Args...)>{};
			}

			// Please forgive me, Carmack
#			define DEF_UNIFORM_FUNC(_type_, _letter_) \
				template<> auto get_uniform_function(_type_) { return glUniform1 ## _letter_; } \
				template<> auto get_uniform_function(_type_, _type_) { return glUniform2  ## _letter_; } \
				template<> auto get_uniform_function(_type_, _type_, _type_) { return glUniform3  ## _letter_; } \
				template<> auto get_uniform_function(_type_, _type_, _type_, _type_) { return glUniform4  ## _letter_; } \
				\
				template<> auto get_uniform_function(int, _type_ *) { return glUniform1 ## _letter_ ## v; } \
				template<> auto get_uniform_function(int, _type_ const *) { return glUniform1 ## _letter_ ## v; } \
				template<> auto get_uniform_function(int, _type_ ## []) { return glUniform1 ## _letter_ ## v; } \
				template<> auto get_uniform_function(int, _type_ ## [], _type_ ## []) { return glUniform2  ## _letter_ ## v; } \
				template<> auto get_uniform_function(int, _type_ ## [], _type_ ## [], _type_ ## []) { return glUniform3  ## _letter_ ## v; } \
				template<> auto get_uniform_function(int, _type_ ## [], _type_ ## [], _type_ ## [], _type_ ## []) { return glUniform4  ## _letter_ ## v; } \

			// Simple types
			DEF_UNIFORM_FUNC(int, i)
			DEF_UNIFORM_FUNC(unsigned int, ui)
			DEF_UNIFORM_FUNC(float, f)

			// Let's not keep these nasties around longer than necessary...
#			undef DEF_UNIFORM_FUNC


			// Matrix functions
			template<int Cols, int Rows>
			auto get_matrix_function()
			{
				assert(false, "This combination of rows/column is not supported by any uniform matrix function");
				return std::function<void(void)>{};
			}

			template<> auto get_matrix_function<2, 2>() {return glUniformMatrix2fv; }
			template<> auto get_matrix_function<3, 3>() {return glUniformMatrix3fv; }
			template<> auto get_matrix_function<4, 4>() {return glUniformMatrix4fv; }
			template<> auto get_matrix_function<2, 3>() {return glUniformMatrix2x3fv; }
			template<> auto get_matrix_function<3, 2>() {return glUniformMatrix3x2fv; }
			template<> auto get_matrix_function<2, 4>() {return glUniformMatrix2x4fv; }
			template<> auto get_matrix_function<4, 2>() {return glUniformMatrix4x2fv; }
			template<> auto get_matrix_function<3, 4>() {return glUniformMatrix3x4fv; }
			template<> auto get_matrix_function<4, 3>() {return glUniformMatrix4x3fv; }

		public:
			OGLEXPORT uniform();
			OGLEXPORT uniform(program *aProgram, GLuint aLocation);
			OGLEXPORT uniform(uniform &&aUniform);
			OGLEXPORT uniform& operator=(uniform &&aUniform);
			OGLEXPORT ~uniform();

			template<typename ...Args>
			void set(Args... aArgs)
			{
				assert(my_program->is_bound());
				auto f = get_uniform_function(aArgs...);
				f(my_location, aArgs...);
			}

			template<int Cols, int Rows = Cols>
			void set(float *aMatrix, int aCount = 1, bool aTranspose = false)
			{
				assert(my_program->is_bound());
				auto f = get_matrix_function<Cols, Rows>();
				f(my_location, aCount, aTranspose, aMatrix);
			}

			template<int Cols, int Rows, int Size>
			void set(float(&aMatrix)[Size], bool aTranspose = false)
			{
				set(aMatrix, Size / (Cols * Rows), aTranspose);
			}

		private:
			program *my_program;
			GLuint my_location;
		};
	public:
		OGLEXPORT program();
		OGLEXPORT ~program();
		OGLEXPORT program(program &&);
		OGLEXPORT program &operator=(program &&);
		OGLEXPORT operator GLuint();

		OGLEXPORT void attach(shader &aShader);
		OGLEXPORT void detach(shader &aShader);
		OGLEXPORT bool link();

		OGLEXPORT uniform get_uniform(const std::string &aName);
		OGLEXPORT uniform get_uniform(GLuint aLocation);

		OGLEXPORT static void bind(program &aBindable, GLuint aConstant);
		OGLEXPORT static void unbind(program &aBindable, GLuint aConstant);
		OGLEXPORT static stack_type &get_states();

	private:
		void detach_all();

	private:
		GLuint my_program;
	};

	OGLEXPORT program quick_shader(std::initializer_list<std::string> aShaders);
}