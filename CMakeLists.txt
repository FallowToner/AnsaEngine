set(CMAKE_VER 3.16)
cmake_minimum_required(VERSION ${CMAKE_VER})

set(CMAKE_CXX_STANDARD 20)
set(EXTERN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extern)
set(PROJECT_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

enable_testing()
include(GoogleTest)

#add_subdirectory(extern)
add_subdirectory(src)
#add_subdirectory(tests)

