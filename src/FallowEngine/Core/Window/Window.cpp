#include "Window.hpp"

#ifdef WIN32
	#include <gl/glew.h>
#else
	#include <GL/glew.h>
#endif

#include <spdlog/spdlog.h>

namespace fallow
{
	namespace core
	{
		Window::Window(int          width       = 500,
		               int          hight       = 600,
		               std::string  title       = "TestEngine",
		               GLFWmonitor* monitor     = nullptr,
		               GLFWwindow*  shareWindow = nullptr)
		{
			if (!glfwInit())
			{
				spdlog::error("Failed to initialize GLFW");
				throw std::runtime_error("Failed to initialize GLFW");
			}
			mWindowHandle = glfwCreateWindow(width, hight, title.c_str(), monitor, shareWindow);
			if (!mWindowHandle)
			{
				spdlog::error("Failed to create window");
				throw std::runtime_error("Failed to create window");
			}
			if (!glewInit())
			{
				spdlog::error("Failed to initialize GLEW");
				throw std::runtime_error("Failed to initialize GLEW");
			}

			const auto framebufferSizeCallback = [](GLFWwindow* winodw, int width, int height)
			{ glViewport(0, 0, width, height); };

			glfwMakeContextCurrent(mWindowHandle);
			glfwSetFramebufferSizeCallback(mWindowHandle, framebufferSizeCallback);
		}
		Window::~Window()
		{
			glfwDestroyWindow(mWindowHandle);
			glfwTerminate();
		}
	} // namespace core
} // namespace fallow
