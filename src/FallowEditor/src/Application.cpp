#include <FallowEngine.hpp>
#include <iostream>

int main()
{
	fallow::core::Window       window(500, 600, "hello", nullptr, nullptr);
	fallow::math::Matrix<2, 2> matrix(1);
	fallow::math::Matrix<2, 3> matrix3(10);

	matrix.setDiagonal(5);

	const auto result = fallow::math::Matrix<2, 3>::transparentMatrix(matrix3);
	std::cout << result << '\n';
	// std::cout << matrix << '\n';
}