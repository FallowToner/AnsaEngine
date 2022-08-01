cmake_minimum_required(VERSION ${CMAKE_VER})

project(FallowModules)

add_subdirectory(Audio)
add_subdirectory(Graphics)
add_subdirectory(IO)

add_library(FallowModules INTERFACE)

target_link_libraries(${PROJECT_NAME} INTERFACE FallowAudio FallowGraphics FallowIO)