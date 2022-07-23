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
			void bindBuffer();
		};
	} // namespace graphics
} // namespace fallow

#endif // VAO_Hpp