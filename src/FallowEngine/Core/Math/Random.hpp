#ifndef Random_Hpp
#define Random_Hpp

#include <cstdint>

namespace fallow
{
	namespace math
	{
		class RandomGenerator
		{
			RandomGenerator(std::int64_t seed_) : seed{ seed_ }
			{
				
			}
		private:
			std::int64_t seed;
		};
	} // namespace math
} // namespace fallow

#endif // Random_Hpp