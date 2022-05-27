#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "IWindow.hpp"

namespace API{
    namespace Platform
    {
        class GLFW_Window : IWindow
        {
        public:

        private:
            GLFWwindow* pWindow;
        };
    }
}

