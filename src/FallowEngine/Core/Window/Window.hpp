#ifndef Window_hpp
#define Window_hpp

#include <gl/glew.h>

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