#pragma once

#include "GlfwSettingData.hpp"

#include <string>

namespace API::Platform
{
    class GlfwSettings final
    {
    public:
        void updateSettings();
        void setupSettings(GlfwSettingsData& settings);

    private:
        std::shared_ptr<GlfwSettingsData> settingsData;
    };
}    // namespace API::Platform