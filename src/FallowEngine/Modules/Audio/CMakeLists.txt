cmake_minimum_required(VERSION ${CMAKE_VER})

set(CMAKE_CXX_STANDARD_REQUIRED 20)

add_library(FallowAudio STATIC
			AudioManager.cpp
)

set_target_properties(FallowAudio PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(FallowAudio PUBLIC)
target_link_libraries(FallowAudio PUBLIC)