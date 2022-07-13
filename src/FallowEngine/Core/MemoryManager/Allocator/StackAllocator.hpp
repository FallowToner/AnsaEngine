#ifndef StackAllocator_Hpp
#define StackAllocator_Hpp

#include <memory>

namespace fallow
{
	namespace memory
	{
		template <typename T>
		class StackAllocator
		{
		public:
			// Requirments by std::allocator for using with STL Containers
			using value_type      = T;
			using size_type       = std::size_t;
			using difference_type = std::ptrdiff_t;
			using marker_type     = std::uint32_t;

			value_type* allocate(value_type* pointer, size_type size) {}
			void        deallocate() {}
		};
	} // namespace memory
} // namespace fallow

#endif // StackAllocator_Hpp