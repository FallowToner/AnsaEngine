#ifndef Matrix_Hpp
#define Matrix_Hpp

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>


namespace fallow
{
	namespace math
	{

		template <std::size_t Rows = 1, std::size_t Columns = 1, typename T = float>
		class Matrix
		{
		public:
			Matrix() { dataMatrix = {}; }

			explicit Matrix(const T& value)
			{
				for (std::size_t row = 0; row < Rows; ++row)
				{
					for (std::size_t column = 0; column < Columns; ++column)
					{
						dataMatrix[row][column] = value;
					}
				}
			}

			template <typename... Args, class = std::enable_if_t<sizeof...(Args) != 1>>
			Matrix(Args&&... args)
			{
				static_assert(sizeof...(args) == Rows * Columns);
				std::array            pack     = {args...};
				constexpr std::size_t arrayLen = pack.size();
				std::size_t           rowSize  = dataMatrix[0].size();
				for (std::size_t i = 0; i < arrayLen; ++i)
				{
					std::size_t row      = i / rowSize;
					std::size_t col      = i % rowSize;
					dataMatrix[row][col] = pack[i];
				}
			}

			Matrix& operator+=(const Matrix& rhs)
			{
				assert(this == rhs);
				for (std::size_t row = 0; row < Rows; ++row)
				{
					for (std::size_t column = 0; column < Columns; ++column)
					{
						dataMatrix[row][column] += rhs.dataMatrix[row][column];
					}
				}
				return *this;
			}
			Matrix& operator-=(const Matrix& rhs)
			{
				assert(this == rhs);
				for (std::size_t row = 0; row < Rows; ++row)
				{
					for (std::size_t column = 0; column < Columns; ++column)
					{
						dataMatrix[row][column] -= rhs.dataMatrix[row][column];
					}
				}
				return *this;
			}
			Matrix& operator*=(const Matrix& rhs)
			{
				assert(this == rhs);

				return *this;
			}
			Matrix& operator/=(const Matrix& rhs)
			{
				// TODO : Create function for transparent matrix and use it here.
				// Because /= is not defined for mathematical matrix and
				// That`s equal A * B^-1 .

				// I think it should be like Matrix Transparent(const Matrix& rhs)
				// We should return copy bcs we need some more flaxible usage in our /= or / operators
				return *this;
			}

			Matrix operator+(const Matrix& rhs) {}
			Matrix operator-(const Matrix& rhs) {}
			Matrix operator*(const Matrix& rhs) {}
			Matrix operator/(const Matrix& rhs) {}

			bool operator==(const Matrix& rhs)
			{
				std::size_t rowSize    = dataMatrix[0].size();
				std::size_t columnSize = dataMatrix.size();

				std::size_t rhsRowSize    = rhs.dataMatrix[0].size();
				std::size_t rhsColumnSize = rhs.dataMatrix.size();

				return (rowSize == rhsRowSize) && (columnSize == rhsColumnSize);
			}

			friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
			{
				for (const auto& row : matrix.dataMatrix)
				{
					for (const auto& element : row)
					{
						os << element << ' ';
					}
					os << '\n';
				}
				return os;
			}


		public:
			std::size_t getRowsCount() { return Rows; }
			std::size_t getColumnsCount() { return Columns; }

		private:
			using matrix = std::array<std::array<T, Rows>, Columns>;
			matrix dataMatrix;
		};

	} // namespace math
} // namespace fallow


#endif // Matrix_Hpp