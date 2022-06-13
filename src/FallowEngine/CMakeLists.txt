cmake_minimum_required(VERSION ${CMAKE_VER})
project(FallowEngine CXX)

if(WIN32 OR MSVC)
        set(CMAKE_TOOLCHAIN_FILE "C:\\Tools\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(ENGINE_SOURCES
        #----Modules--------files
        #==========================
        Modules/Audio/AudioManager.cpp
	#==========================
        Modules/IO/Keyboard.cpp
        Modules/IO/InputManager.cpp
        #==========================

        #----Core------files
	#==========================
        Core/Window/Window.cpp
        Core/Window/WindowState.cpp
        #==========================
)

add_library(${PROJECT_NAME} STATIC ${ENGINE_SOURCES})

include(FindOpenGL)
include(FindGLEW)

find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)


set_target_properties(${PROJECT_NAME} PROPERTIES
       INTERFACE_INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR}
       ${CMAKE_CURRENT_SOURCE_DIR}/include
       ${CMAKE_CURRENT_SOURCE_DIR}/
       )

#----INCLUDE_LIBRARIES--DIRECTORIES----
target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${GLEW_INCLUDE_DIRS}
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        )
#--------------------------------------
#----LINK_LIBRARIES--------------------
target_link_libraries(${PROJECT_NAME}
        PUBLIC glm::glm
        #GL
        OpenGL::GL
        glfw
        GLEW::glew
        fmt::fmt
        spdlog::spdlog spdlog::spdlog_header_only
        )
#--------------------------------------