cmake_minimum_required(VERSION ${CMAKE_VER})

set(CMAKE_CXX_STANDARD_REQUIRED 20)

add_library(FallowAllocator INTERFACE
			Matrix.hpp
			)

set_target_properties(FallowAllocator PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(FallowAllocator INTERFACE)
target_link_libraries(FallowAllocator INTERFACE )