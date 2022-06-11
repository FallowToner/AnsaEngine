cmake_minimum_required(VERSION 3.16)

project(TrueEditor CXX)

add_executable(${PROJECT_NAME} src/Application.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC TrueEngine)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)