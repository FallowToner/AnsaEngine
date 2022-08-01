cmake_minimum_required(VERSION ${CMAKE_VER})

project(FallowGraphics)

add_subdirectory(Buffers)
add_subdirectory(Components)

add_library(${PROJECT_NAME} INTERFACE )

target_link_libraries(${PROJECT_NAME} INTERFACE GraphicsComponents GraphicsBuffers)