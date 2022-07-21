cmake_minimum_required(VERSION ${CMAKE_VER})

set(CMAKE_CXX_STANDARD_REQUIRED 20)

add_library(FallowAllocator STATIC
			StackAllocator.hpp
			StackAllocator.cpp)

set_target_properties(FallowAllocator PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(FallowAllocator PUBLIC)
target_link_libraries(FallowAllocator PUBLIC)