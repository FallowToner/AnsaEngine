cmake_minimum_required(VERSION 3.16)

project(TrueEngine)

set(SOURCES src/IWindow.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCES})
target_compile_definitions(${PROJECT_NAME} PUBLIC TRUE_PLATFORM_LINUX TRUE_BUILD_DLL)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${PROJECT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)


target_link_libraries(${PROJECT_NAME}
        PUBLIC

        PRIVATE
        )