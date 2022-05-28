#include "Platform/Settings/GlfwSettings.hpp"

void API::Platform::GlfwSettings::updateSettings() {
    std::string path = "\"TrueEngine/API/Assets/Settings.ini\"";
    settingsData->loadFromFile(path);
}
