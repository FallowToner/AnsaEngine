#pragma once

#include <memory>


namespace API
{
    namespace Platform
    {
        enum class SettingsHint{
            // The default hint value.
            INT_WINDOW_HIGHT,
            INT_WINDOW_WIDTH,
            STRING_WINDOW_TITLE,
            INT_WINDOW_FRAMERATE,

            // Render API Specific Hints
            BOOL_VSYNC,
            
        };

        class ISettings
        {
        public:
            virtual std::shared_ptr<ISettings> buildSettings()                      = 0;
            virtual std::shared_ptr<ISettings> loadSettings(std::string_view& path) = 0;
        };
    }   // namespace Platform
}   // namespace API