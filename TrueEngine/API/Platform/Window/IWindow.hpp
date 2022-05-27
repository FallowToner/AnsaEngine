#pragma once

// If we need to use as DLL
//#include "API/Platform/Core.hpp"

namespace API
{
    namespace Platform
    {
        class IWindow
        {
        public:
            static void resolve();
        };
    }
}    // namespace API