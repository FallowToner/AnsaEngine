cmake_minimum_required(VERSION 3.16)
project(TrueEngine CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SOURCES
        #----Audio--------files
        src/Audio/AudioManager.cpp

        #---Platform------files
        src/Platform/Window/Window.cpp
        #---------------------

        #---IO------------files
        src/IO/Keyboard.cpp
        #---------------------
        )

# Add the TrueEngine used libraries
add_subdirectory(../external/glfw   ${CMAKE_BINARY_DIR}/glfw    )
add_subdirectory(../external/glm    ${CMAKE_BINARY_DIR}/glm     )
add_subdirectory(../external/glew   ${CMAKE_BINARY_DIR}/glew    )
add_subdirectory(../external/fmt    ${CMAKE_BINARY_DIR}/fmt     )
add_subdirectory(../external/EASTL  ${CMAKE_BINARY_DIR}/EASTL   )
#----------------------------------

add_library(${PROJECT_NAME} STATIC ${SOURCES})

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
        ${GLEW_INCLUDE_DIRS}
        glfw
        fmt
        )

target_link_libraries(${PROJECT_NAME}
        PUBLIC glm
        PRIVATE
        glfw
        ${GLEW_LIBRARIES}
        fmt
        ${EASTL_LIBRARY}
        )