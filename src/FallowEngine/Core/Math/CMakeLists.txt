cmake_minimum_required(VERSION ${CMAKE_VER})

set(CMAKE_CXX_STANDARD_REQUIRED 20)

add_library(FallowMath INTERFACE
			Matrix.hpp
			MatrixTraits.hpp

			Random.hpp
)

set_target_properties(FallowMath PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(FallowMath PRIVATE)
target_link_libraries(FallowMath PRIVATE )