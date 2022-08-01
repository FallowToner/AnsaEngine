cmake_minimum_required(VERSION ${CMAKE_VER})
if(WIN32 OR MSVC)
    set(CMAKE_TOOLCHAIN_FILE "C:\\Tools\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake")
    set(CMAKE_PREFIX_PATH "C:\\Tools\\vcpkg\\packages\\")
endif()
project(GraphicsBuffers)

find_package(glfw3 REQUIRED)
include(FindOpenGL)
include(FindGLEW)


add_library(${PROJECT_NAME} INTERFACE
            VAO.hpp
            VBO.hpp
            ../FallowAlias.hpp
)

target_include_directories(${PROJECT_NAME} INTERFACE
                            ${GLEW_INCLUDE_DIRS}
                            )
target_link_libraries(${PROJECT_NAME} INTERFACE
                        OpenGL::GL
                        glfw
                        GLEW::glew)