#ifndef Log_Behavior_Hpp
#define Log_Behavior_Hpp

#include <array>
#include <map>
#include <string>

namespace Logs
{
	class LogBehavior
	{
	public:
		template <typename E>
		static constexpr auto as_integer(E e) noexcept
		{
			return static_cast<std::underlying_type_t<E>>(e);
		}

		enum class LogLevel
		{
			LOG_OFF     = 0,
			LOG_TRACE   = 1,
			LOG_INFO    = 2,
			LOG_DEBUG   = 3,
			LOG_WARNING = 4,
			LOG_ERROR   = 5,
			LOG_FATAL   = 6,
		};

		static constexpr std::array levelNames{"TRACE", "INFO", "DEBUG", "WARNING", "ERROR", "FATAL"};
	};
} // namespace Logs

#endif // Log_Behavior_Hpp
