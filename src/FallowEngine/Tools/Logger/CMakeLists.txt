cmake_minimum_required(VERSION ${CMAKE_VER})

set(CMAKE_CXX_STANDARD_REQUIRED 20)

add_library(FallowLogger STATIC
			LogBehavior.hpp

			LogStyle.cpp
			LogStyle.hpp

			Logging.cpp
			Logging.hpp

			Container.cpp
			Container.hpp
)

set_target_properties(FallowLogger PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(FallowLogger PUBLIC)
target_link_libraries(FallowLogger PUBLIC)