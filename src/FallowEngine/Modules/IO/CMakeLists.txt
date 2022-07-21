cmake_minimum_required(VERSION ${CMAKE_VER})

set(CMAKE_CXX_STANDARD_REQUIRED 20)

add_library(FallowIO STATIC
		InputManager.cpp
		Keyboard.cpp
)

set_target_properties(FallowIO PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(FallowIO PUBLIC)
target_link_libraries(FallowIO PUBLIC)