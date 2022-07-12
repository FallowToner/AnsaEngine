#include <FallowEngine.hpp>
#include <iostream>

int main()
{
	fallow::core::Window window(500, 600,"hello",nullptr,nullptr);
	fallow::math::Matrix<2, 2> matrix(5,6,7,8);
	fallow::math::Matrix<2, 2> matrix2(6);
	matrix += matrix2;
	std::cout << matrix;
}