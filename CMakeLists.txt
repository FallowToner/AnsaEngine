cmake_minimum_required(VERSION 3.16)
project(TrueSoul)

set(CMAKE_CXX_STANDARD 20)

include_directories(TrueEngine/API)
add_subdirectory(TrueEngine)
add_subdirectory(TrueEditor)
