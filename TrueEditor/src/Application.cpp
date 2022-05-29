#include <TrueEngine.hpp>
#include <iostream>

int main()
{
	std::cout << "Is Work!" << '\n';
	TrueEngine::Platform::Window window{};

	window.CreateWindow();
}