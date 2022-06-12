cmake_minimum_required(VERSION ${CMAKE_VER})
project(FallowEngine CXX)


set(CMAKE_TOOLCHAIN_FILE "C:\\Tools\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake")


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
        #GL
        GLEW::GLEW
        glfw
        fmt::fmt
        spdlog::spdlog spdlog::spdlog_header_only
        )
#--------------------------------------