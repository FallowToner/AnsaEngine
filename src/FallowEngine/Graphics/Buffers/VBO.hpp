#ifndef VBO_Hpp
#define VBO_Hpp

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
		template <typename T>
		requires std::is_arithmetic_v<T>
		class VBO final
		{
			VBO(GLuint id_, BufferType bufferType_, DrawType drawType_) : id{id_}, bufferType{bufferType_}
			{
				glGenBuffers(1, &id);
				bindBuffer(bufferType);
			}

			void bindBuffer(BufferType bufferType) { glBindBuffer(as_integer(bufferType), id); }
			void unbindBuffer() { glBindBuffer(drawType, 0); }
			void loadBuffer(const T* buffer, DrawType drawingType)
			{
				drawType = drawingType;
				glBufferData(as_integer(bufferType), sizeof(buffer), buffer, as_integer(drawingType));
			}

			~VBO() 
			{
				glDeleteBuffers(1, &id);
				this->unbindBuffer();
			}
		private:
			GLuint     id;
			BufferType bufferType;
			DrawType   drawType;
		};
	} // namespace graphics
} // namespace fallow

#endif // VBO_Hpp