#pragma once

#include "Tools/IniReader/ini.hpp"

#include <memory>
#include <string>

namespace API::Platform
{
    class GlfwSettingsData
    {
    public:
        virtual ~GlfwSettingsData() = default;

    public:
        virtual void loadFromFile(std::string& path);
        virtual void loadInFIle(std::string& path);

    private:
        int         windowWidth;
        int         windowHeight;
        std::string windowTitle;
        int         frameRate;
    };
}    // namespace API::Platform