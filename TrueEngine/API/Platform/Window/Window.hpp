#ifndef Window_hpp
#define Window_hpp

#include "WindowState.hpp"

namespace TrueEngine
{
	namespace Platform
	{
		/**
		 * @brief Wrapper for GLFW window and callback functions.
		 * @ingroup Platform
		 */
		class Window
		{
		public:
			Window(int width, int hight, std::string title, GLFWmonitor* monitor, GLFWwindow* shareWindow);
			virtual ~Window();

			Window(const Window&) = delete;
			Window(Window&&) = delete;
			Window& operator=(const Window&) = delete;
			Window& operator=(Window&&) = delete;

		private:
			GLFWwindow* mWindowHandle;
			WindowState mCurrentState{};
		};
	} // namespace Platform
} // namespace TrueEngine

#endif // Window_hpp