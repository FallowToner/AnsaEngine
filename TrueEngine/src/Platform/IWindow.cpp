#include "API/Platform/Window/IWindow.hpp"

#include <iostream>

void API::Platform::IWindow::resolve()
{
    std::cout << "Resolve" << '\n';
}
