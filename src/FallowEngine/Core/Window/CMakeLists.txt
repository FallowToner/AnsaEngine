cmake_minimum_required(VERSION ${CMAKE_VER})
if(WIN32 OR MSVC)
    set(CMAKE_TOOLCHAIN_FILE "C:\\Tools\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake")
    set(CMAKE_PREFIX_PATH "C:\\Tools\\vcpkg\\packages\\")
endif()
project(WindowModule)

include(FindOpenGL)
include(FindGLEW)
find_package(glfw3 CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_library(${PROJECT_NAME}
        Window.cpp
        Window.hpp
        WindowState.cpp
        WindowState.hpp
        WindowTraits.hpp
        )

#target_compile_definitions(${PROJECT_NAME} PUBLIC SPDLOG_COMPILED_LIB SPDLOG_FMT_EXTERNAL)

target_include_directories(${PROJECT_NAME} PRIVATE
        ${GLEW_INCLUDE_DIRS}
        )
target_link_libraries(${PROJECT_NAME} PRIVATE
        OpenGL::GL
        glfw
        GLEW::glew
        spdlog::spdlog_header_only
        )