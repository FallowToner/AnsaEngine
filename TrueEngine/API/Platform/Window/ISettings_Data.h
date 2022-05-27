#pragma once

#include <memory>
#include <string>

namespace API
{
    namespace Platform
    {
      class ISettings_Data
      {
          virtual std::shared_ptr<ISettings_Data> buildData() = 0;
          virtual std::shared_ptr<ISettings_Data> loadData(std::string_view& path) = 0;
      };

      class GLFW_SettingsData : public ISettings_Data
      {
      public:

private:
          int         windowWidth;
          int         windowHeight;
          std::string windowTitle;
          int         frameRate;
      };
    }
} // namespace API