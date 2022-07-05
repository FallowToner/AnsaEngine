cmake_minimum_required(VERSION ${CMAKE_VER})


find_package(glfw3 REQUIRED)
include(FindOpenGL)
include(FindGLEW)


add_library(WindowModule
            Window.cpp
            Window.hpp
            WindowState.cpp
            WindowState.hpp)

target_include_directories(WindowModule PUBLIC
                            ${GLEW_INCLUDE_DIRS}
                            )
target_link_libraries(WindowModule PUBLIC
                        OpenGL::GL
                        glfw
                        GLEW::glew)