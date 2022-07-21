cmake_minimum_required(VERSION ${CMAKE_VER})

project(FallowEditor CXX)
set(CMAKE_CXX_STANDARD_REQUIRED 20)

add_executable(${PROJECT_NAME} src/Application.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC FallowEngine)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)