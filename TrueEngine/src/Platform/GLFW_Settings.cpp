
#include "Platform/Window/GLFW_Settings.hpp"

std::shared_ptr<API::Platform::ISettings> API::Platform::GLFW_Settings::buildSettings()
{
    return nullptr;
}

std::shared_ptr<API::Platform::ISettings> API::Platform::GLFW_Settings::loadSettings(std::string_view& path)
{
    return std::shared_ptr<ISettings>();
}
