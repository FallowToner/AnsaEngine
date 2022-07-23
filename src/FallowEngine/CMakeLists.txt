cmake_minimum_required(VERSION ${CMAKE_VER})
project(FallowEngine CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(Core)
add_subdirectory(Modules)
add_subdirectory(Tools)
add_subdirectory(Graphics)

set(ENGINE_SOURCES
      EntryPoint/Entrypoint.cpp
)

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
        #Core
        WindowModule
        FallowAllocator
        FallowMath

        #Tools
        FallowLogger

        # Modules
        FallowIO
        FallowAudio

        #Graphics
        FallowGraphics
        )
#--------------------------------------