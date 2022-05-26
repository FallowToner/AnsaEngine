#pragma once

#ifdef TRUE_PLATFORM_LINUX
    #ifdef TRUE_BUILD_DLL
        #define ENGINE_API __attribute__((visibility("default")))
    #else
        #define ENGINE_API
    #endif    // TRUE_BUILD_DLL
#endif        // TRUE_PLATFORM_LINUX
