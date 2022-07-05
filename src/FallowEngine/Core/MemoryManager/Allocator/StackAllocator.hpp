#ifndef StackAllocator_Hpp
#define StackAllocator_Hpp

#include <memory>

namespace fallow
{
	namespace memory
	{
		template <typename T>
		class StackAllocator : public std::allocator<T>
		{

		};
	} // namespace memory
} // namespace fallow

#endif // StackAllocator_Hpp