#ifndef Window_hpp
#define Window_hpp

#ifdef WIN32
	#include <gl/glew.h>
#else
	#include <GL/glew.h>
#endif

#include "WindowState.hpp"
//
#include <GLFW/glfw3.h>

namespace fallow
{
	namespace core
	{
		class Window
		{
		public:
			Window(int width, int height, std::string title, GLFWmonitor* monitor, GLFWwindow* shareWindow);
			virtual ~Window();

			Window(const Window&) = delete;
			Window(Window&&)      = delete;
			Window& operator=(const Window&) = delete;
			Window& operator=(Window&&) = delete;

		private:
			GLFWwindow* mWindowHandle;
			WindowState mCurrentState{};
		};
	} // namespace core
} // namespace fallow

#endif // Window_hpp