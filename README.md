# AnsaEngine

The AnsaEngine is a lightweight cross-platform game/graphics engine written in C++.
True Engine is meant to be compiled with your game and is not a standalone development environment with a GUI as found in Unity/UE/Godot. 
It should simply be used as a library.

In this educational project I want to get experience in developent Game Engine architecture.
True Engine is built using an object-oriented approach to hide the hairy details of the engine from the game developer. 
This means that you can easily extend upon the engine and use the included tools without having to concern yourself with True Engine implementation.

AnsaEngine use CMake build-system to compile and link libraries. 
This means that you can use any C++ compiler you want to compile the engine.

## Installing and running AnsaEngine
1. [Clone the repository](https://github.com/ansa-sequence/TrueSoul_Engine)
2. [Install vcpkg](https://vcpkg.io/en/index.html)
3. Install dependencies :
    - vcpkg install glfw3
    - vcpkg install glm
    - vcpkg install glew
    - vcpkg install fmt
    - vcpkg install spdlog
    - vcpkg install imgui
4. Run the project
