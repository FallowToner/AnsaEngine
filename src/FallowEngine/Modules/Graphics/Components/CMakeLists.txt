cmake_minimum_required(VERSION ${CMAKE_VER})
# if(WIN32 OR MSVC)
#     set(CMAKE_TOOLCHAIN_FILE "C:\\Tools\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake")
#     set(CMAKE_PREFIX_PATH "C:\\Tools\\vcpkg\\packages\\")
# endif()
project(GraphicsComponents)

#find_package(SDL2 REQUIRED)

add_library(${PROJECT_NAME} INTERFACE
            Mash.hpp
)

target_include_directories(${PROJECT_NAME} INTERFACE
                            )
target_link_libraries(${PROJECT_NAME} INTERFACE
SDL2::SDL2-static  SDL2::SDL2main)