cmake_minimum_required(VERSION ${CMAKE_VER})

project(FallowCore)

add_subdirectory(Window)
add_subdirectory(MemoryManager)
add_subdirectory(Math)

add_library(FallowCore INTERFACE )
target_link_libraries(FallowCore INTERFACE WindowModule FallowMath FallowAllocator)