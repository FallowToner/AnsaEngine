#include <TrueEngine.hpp>
#include <iostream>

int main()
{
    API::Platform::IWindow::resolve();
    std::cout << "Diffs" << '\n';
}