#ifndef Window_hpp
#define Window_hpp

#include "WindowState.hpp"

namespace fallow
{
	namespace core
	{
		/**
		 * @brief Wrapper for GLFW window and callback functions.
		 * @ingroup platform
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
	} // namespace platform
} // namespace TrueEngine

#endif // Window_hpp