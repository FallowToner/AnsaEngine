#ifndef VAO_Hpp
#define VAO_Hpp

// clang-format off
#ifdef WIN32
	#include <gl/glew.h>
	#include <GLFW/glfw3.h>
#else
	#include <GL/glew.h>
	#include <GLFW/glfw3.h>
#endif
// clang-format on

#include <type_traits>

#include "../FallowAlias.hpp"

namespace fallow
{
	namespace graphics
	{
		class VAO final
		{
		public:
			VAO(GLuint id_) : id{id_}
			{
				glGenVertexArrays(1, &id);
				bindBuffer();
			}
			void bindBuffer() { glBindVertexArray(id); }
			void unbindBuffer() { glBindVertexArray(0);}

			~VAO()
			{
				glDeleteVertexArrays(1, &id);
				unbindBuffer();
			}

		private:
			GLuint id;
		};
	} // namespace graphics
} // namespace fallow

#endif // VAO_Hpp