cmake_minimum_required(VERSION 3.16)
project(TrueEngine CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#set(CMAKE_CXX_FLAGS )

set(SOURCES
        #----Audio--------files
        src/Audio/AudioManager.cpp

        #---Platform------files
        src/Platform/Window/Window.cpp
        src/Platform/Window/WindowState.cpp
        #---------------------

        #---IO------------files
        src/IO/Keyboard.cpp
        API/IO/InputManager.cpp API/IO/InputManager.h
        )
#--------------------

add_library(${PROJECT_NAME} STATIC ${SOURCES})

find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)


set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/
        )

#----INCLUDE_LIBRARIES--DIRECTORIES----
target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        )
#--------------------------------------

#----LINK_LIBRARIES--------------------
target_link_libraries(${PROJECT_NAME}
        PUBLIC glm::glm
        PRIVATE
        GL
        GLEW::GLEW
        glfw
        fmt::fmt
        spdlog::spdlog spdlog::spdlog_header_only
        )
#--------------------------------------