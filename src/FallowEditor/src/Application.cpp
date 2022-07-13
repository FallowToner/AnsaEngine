#include <FallowEngine.hpp>
#include <iostream>

int main()
{
	fallow::core::Window window(500, 600,"hello",nullptr,nullptr);
	fallow::math::Matrix<2, 2> matrix(1);
	fallow::math::Matrix<2, 2> matrix2(6);
	fallow::math::Matrix<2, 3> matrix3(10);
	//matrix = matrix3;
	const auto& matrix4 =  matrix * matrix3;
	std::cout << matrix4;
}