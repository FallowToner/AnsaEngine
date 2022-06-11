#pragma once

#include "WindowData.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

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
			void CreateWindow();

		private:
			using WindowHandler = GLFWwindow*;
			WindowHandler windowHandler;
		};
	} // namespace Platform
} // namespace TrueEngine