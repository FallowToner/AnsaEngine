cmake_minimum_required(VERSION 3.16)

project(TrueEngine)

#add_subdirectory(external/googletest)

#SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)	# needed due to tbb-homebrew bug https://github.com/Homebrew/homebrew-core/pull/36175

set(SOURCES
        src/Platform/IWindow.cpp
        src/Platform/GlfwWindow.cpp
        src/Platform/Settings/GlfwSettingsData.cpp
        src/Platform/Settings/GlfwSettings.cpp

        src/Audio/IAudio.cpp
        src/IO/IKeyboard.cpp
        src/glad.c
        )

add_library(${PROJECT_NAME} STATIC ${SOURCES})
#target_compile_definitions(${PROJECT_NAME} PUBLIC TRUE_PLATFORM_LINUX TRUE_BUILD_DLL)

set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        glm
    PRIVATE
        ${PROJECT_SOURCE_DIR}
        glad
        glfw
        #googletest
)


target_link_libraries(${PROJECT_NAME}
        PRIVATE GL GLU glfw)