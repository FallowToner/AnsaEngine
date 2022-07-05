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
        #==========================
)


add_subdirectory(Core)


find_package(glm REQUIRED)
find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)

add_library(${PROJECT_NAME} ${ENGINE_SOURCES})

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
        PUBLIC
        WindowModule
        FallowAllocator
        glm::glm
        fmt::fmt
        spdlog::spdlog spdlog::spdlog_header_only
        )
#--------------------------------------