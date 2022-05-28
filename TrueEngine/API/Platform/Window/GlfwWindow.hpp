#pragma once

#include "IWindow.hpp"
#include "Platform/Settings/GlfwSettings.hpp"

#include <glad/glad.h>
#include <glm/glm.hpp>
//
#include <GLFW/glfw3.h>

namespace API::Platform
{
    class GlfwWindow : IWindow
    {
    public:
    private:
        GLFWwindow*                   pWindow;
        std::shared_ptr<GlfwSettings> pSettings;
    };
}    // namespace API::Platform
