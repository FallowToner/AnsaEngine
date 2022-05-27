#pragma once

#include "ISettings_Data.h"
#include "Platform/Settings/ISettings.hpp"

#include <string>

namespace API
{
    namespace Platform
    {
        class GLFW_Settings : public ISettings
        {
            std::shared_ptr<ISettings> buildSettings() override;
            std::shared_ptr<ISettings> loadSettings(std::string_view& path) override;

        private:
            int         windowWidth;
            int         windowHeight;
            std::string windowTitle;
            int         frameRate;
        };
    } // namespace Platform
}    // namespace API