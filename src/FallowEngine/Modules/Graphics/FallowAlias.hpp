#ifndef FallowAlias_Hpp
#define FallowAlias_Hpp

// clang-format off
#ifdef WIN32
	#include <gl/glew.h>
	#include <GLFW/glfw3.h>
#else
	#include <GL/glew.h>
	#include <GLFW/glfw3.h>
#endif
// clang-format on

#include <array>
#include <type_traits>

namespace fallow
{
	namespace graphics
	{
		enum class BufferType
		{
			ElementArray = GL_ELEMENT_ARRAY_BUFFER,
			Array        = GL_ARRAY_BUFFER,
			Query        = GL_QUERY_BUFFER,
			Texture      = GL_TEXTURE_BUFFER,
			Unform       = GL_UNIFORM_BUFFER,
		};

		enum class DrawType
		{
			Static  = GL_STATIC_DRAW,
			Dynamic = GL_DYNAMIC_DRAW,
			Mix     = GL_STREAM_DRAW
		};

		template <typename E>
		static constexpr auto as_integer(E e) noexcept
		{
			return static_cast<std::underlying_type_t<E>>(e);
		}

		template<typename T>
		struct is_array : std::is_array<T>
		{};

		// This required for supporting std::array like template parametr in binding VBO
		template<typename T, std::size_t Size> 
		struct is_array<std::array<T, Size>> : std::true_type
		{};
	} // namespace graphics
} // namespace fallow

#endif // FallowAlias_Hpp