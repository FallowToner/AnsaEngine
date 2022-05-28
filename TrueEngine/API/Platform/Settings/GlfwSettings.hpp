#pragma once

#include "GlfwSettingData.hpp"

#include <string>

namespace API::Platform
{
    class GlfwSettings final
    {
    public:
        void updateSettings();
    private:
        std::shared_ptr<GlfwSettingsData> settingsData;
    };
}    // namespace API::Platform