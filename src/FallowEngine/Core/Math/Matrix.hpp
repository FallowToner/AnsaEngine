#ifndef Matrix_Hpp
#define Matrix_Hpp

#include <array>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <type_traits>

#include "MatrixTraits.hpp"

#ifdef NDEBUG
#define NDEBUG
#endif // NDEBUG

namespace fallow
{
	namespace math
	{
		template <std::size_t Rows = 1, std::size_t Columns = 1, typename T = float>
		    requires std::is_arithmetic_v<T>
		class Matrix
		{
		public:
			Matrix() noexcept { dataMatrix = {}; }
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
			template <typename... Args>
			    requires(sizeof...(Args) == Rows * Columns)
			explicit Matrix(Args&&... args)
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

			Matrix(const Matrix& rhs) noexcept            = default;
			Matrix(Matrix&& rhs) noexcept                 = default;
			Matrix& operator=(const Matrix& rhs) noexcept = default;
			Matrix& operator=(Matrix&& rhs) noexcept      = default;

			Matrix& operator+=(const Matrix& rhs)
			{
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
				for (std::size_t row = 0; row < Rows; ++row)
				{
					for (std::size_t column = 0; column < Columns; ++column)
					{
						dataMatrix[row][column] *= rhs.dataMatrix[row][column];
					}
				}
				return *this;
			}

			Matrix operator+(const Matrix& rhs)
			{
				Matrix result = std::move(*this);
				result += rhs;
				return result;
			}
			Matrix operator+(const T& value)
			{
				for (std::size_t row = 0; row < Rows; ++row)
				{
					for (std::size_t column = 0; column < Columns; ++column)
					{
						dataMatrix[row][column] += value;
					}
				}
				return *this;
			}

			Matrix operator-(const Matrix& rhs)
			{
				Matrix result = std::move(*this);
				result -= rhs;
				return result;
			}
			Matrix operator-(const T& value)
			{
				for (std::size_t row = 0; row < Rows; ++row)
				{
					for (std::size_t column = 0; column < Columns; ++column)
					{
						dataMatrix[row][column] -= value;
					}
				}
				return *this;
			}

			Matrix operator*(const Matrix& rhs)
			{
				Matrix result = std::move(*this);
				result *= rhs;
				return result;
			}
			Matrix operator*(const T& value)
			{
				for (std::size_t row = 0; row < Rows; ++row)
				{
					for (std::size_t column = 0; column < Columns; ++column)
					{
						dataMatrix[row][column] *= value;
					}
				}
				return *this;
			}
			template <std::size_t R, std::size_t C, typename Type>
			auto operator*(const Matrix<Rows, Columns, T>& rhs)
			{
				bool isPossible = MatrixTraits_clear<decltype(*this)>::rows == Columns &&
				                  std::is_same_v<typename MatrixTraits_clear<decltype(*this)>::value_type, T>;
				assert(isPossible != true);
				Matrix<MatrixTraits_clear<decltype(*this)>::rows, Columns, T> result{};

				return result;
			}

			constexpr auto& operator[](std::size_t index)
			{
				assert(index < 0 || index < MatrixTraits_clear<decltype(*this)>::rows);
				return dataMatrix[index];
			}
			constexpr auto& operator[](std::size_t index) const
			{
				assert(index < 0 || index < MatrixTraits_clear<decltype(*this)>::rows);
				return dataMatrix[index];
			}

			static constexpr auto transparentMatrix(const Matrix& matrix)
			{
				Matrix<MatrixTraits_clear<decltype(matrix)>::columns, MatrixTraits_clear<decltype(matrix)>::rows>
				  result{};
				for (std::size_t row = 0; row < MatrixTraits_clear<decltype(matrix)>::rows; ++row)
				{
					for (std::size_t column = 0; column < MatrixTraits_clear<decltype(matrix)>::columns; ++column)
					{
						result[column][row] = matrix[row][column];
					}
				}

				return result;
			}
			constexpr auto setDiagonal(const T& value)
			    requires(Rows == Columns)
			{
				for (std::size_t row = 0; row < Rows; ++row)
				{
					for (std::size_t column = 0; column < Columns; ++column)
					{
						if (row == column)
							dataMatrix[row][column] = value;
					}
				}
			}
			constexpr auto        isZeroMatrix() { return dataMatrix.empty(); }
			static constexpr auto determinant(const Matrix& matrix)
			    requires(MatrixTraits_clear<decltype(matrix)>::columns == MatrixTraits_clear<decltype(matrix)>::rows)
			{
				// TODO : At first solve the problem related subMatrix and after return on this.
			}

			bool operator==(const Matrix&) const = default;

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

		private:
			using matrix = std::array<std::array<T, Columns>, Rows>;
			matrix dataMatrix;
		};
	} // namespace math
} // namespace fallow

#endif // Matrix_Hpp