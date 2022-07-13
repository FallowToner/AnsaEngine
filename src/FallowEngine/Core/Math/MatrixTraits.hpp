#ifndef MatrixTraits_Hpp
#define MatrixTraits_Hpp

#include <type_traits>

namespace fallow
{
	namespace math
	{

		template <std::size_t Rows, std::size_t Columns, typename T>
		requires std::is_arithmetic_v<T>
		class Matrix;

		template <typename>
		class MatrixTraits;

		template <std::size_t Rows, std::size_t Columns, typename T>
		class MatrixTraits<fallow::math::Matrix<Rows, Columns, T>>
		{
		public:
			inline static constexpr std::size_t rows{Rows};
			inline static constexpr std::size_t columns{Columns};

			typedef T value_type;
		};

		template <typename T>
		using MatrixTraits_clear = MatrixTraits<std::remove_cvref_t<T>>;
	} // namespace math
} // namespace fallow

#endif // MatrixTraits_Hpp