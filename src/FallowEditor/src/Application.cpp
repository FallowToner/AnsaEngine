#include <FallowEngine.hpp>
#include <iostream>

int main()
{
	fallow::core::Window       window(500, 600, "hello", nullptr, nullptr);
	fallow::math::Matrix<2, 2> matrix(1,2,3,4);
	fallow::math::Matrix<2, 3> matrix3(10);

	std::cout << matrix.determinant();
	// std::cout << matrix << '\n';
}