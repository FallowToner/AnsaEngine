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
			template <typename... Args>
			requires(sizeof...(Args) == Rows * Columns) Matrix(Args&&... args)
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

			Matrix(const Matrix& rhs) noexcept { dataMatrix = rhs.dataMatrix; }
			Matrix(Matrix&& rhs) noexcept { dataMatrix = std::move(rhs.dataMatrix); }
			Matrix& operator=(const Matrix& rhs) noexcept { dataMatrix = rhs.dataMatrix; }
			Matrix& operator=(Matrix&& rhs) noexcept { dataMatrix = std::move(rhs.dataMatrix); }

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
			Matrix operator-(const Matrix& rhs)
			{
				Matrix result = std::move(*this);
				result -= rhs;
				return result;
			}
			Matrix operator*(const Matrix& rhs)
			{
				Matrix result = std::move(*this);
				result *= rhs;
				return result;
			}
			template <std::size_t Rows, std::size_t Columns, typename T>
			const auto operator*(const Matrix<Rows, Columns, T>& rhs)
			{
				bool isPossible = MatrixTraits_clear<decltype(*this)>::rows == Columns &&
				                  std::is_same_v<MatrixTraits_clear<decltype(*this)>::value_type, T>;
				assert(isPossible != true);
				Matrix<MatrixTraits_clear<decltype(*this)>::rows, Columns, T> result{};

				return result;
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

			virtual ~Matrix() = default;

		public:
			static constexpr std::size_t getRowsCount() { return Rows; }
			static constexpr std::size_t getColumnsCount() { return Columns; }

		private:
			using matrix = std::array<std::array<T, Columns>, Rows>;
			matrix dataMatrix;
		};

	} // namespace math
} // namespace fallow


#endif // Matrix_Hpp