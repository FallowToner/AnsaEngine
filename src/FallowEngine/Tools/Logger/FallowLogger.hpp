#ifndef Fallow_Logger_Hpp
#define Fallow_Logger_Hpp

#include <fmt/format.h>
#include <spdlog/spdlog.h>

#include <array>
#include <map>
#include <string>

#define FALLOW_ASSERT(condition, message) static_assert(condition, (message) + #condition)

namespace fallow
{
	namespace tools
	{
		enum class LogBehavior : std::size_t
		{
			LOG_TRACE = 0,
			LOG_DEBUG = 1,
			LOG_INFO  = 2,

			LOG_WARNING = 3,
			LOG_ERROR   = 4,
			LOG_FATAL   = 5,

			LOG_SIZE = 6,
		};

		class FallowLogging
		{
		public:
			FallowLogging(std::size_t logLevel)
			{
				// clang-format offer
#ifdef NDEBUG
				FALLOW_ASSERT(logLevel < 0 ? false : true);
#endif // NDEBUG
       // clang-format on
			}

		private:
			/**
			 * \brief Free function for converting from enumeration to underlying type.
			 * \param[in] value enum value which will be converted into underlying type.
			 */
			template <typename Enumeration>
			static constexpr auto as_integer(const Enumeration value) -> std::underlying_type_t<Enumeration>
			{
				return static_cast<std::underlying_type_t<Enumeration>>(value);
			}
			constexpr auto formaterCMD(const LogBehavior logLevel, const std::string& message)
			{
				std::string formatedString =
				  std::move(fmt::format("{}{}{}", logLevelNames[logLevel], logPatterns.first, message));
				return formatedString;
			}

			constexpr auto formaterJson(const LogBehavior logLevel, const std::string& message)
			{
				std::string formatedString =
				  std::move(fmt::format("{}{}{}", logLevelNames[logLevel], logPatterns.second, message));
				return formatedString;
			}


		public:
			std::map<LogBehavior, std::string> logLevelNames = {
			  {LogBehavior::LOG_TRACE,   std::string("[TRACE]")  },
              {LogBehavior::LOG_DEBUG,   std::string("[DEBUG]")  },
			  {LogBehavior::LOG_INFO,    std::string("[INFO]")   },
              {LogBehavior::LOG_WARNING, std::string("[WARNING]")},
			  {LogBehavior::LOG_ERROR,   std::string("[ERROR]")  },
              {LogBehavior::LOG_FATAL,   std::string("[FATAL]")  },
			};

			// clang-format off
			static std::pair<std::string, std::string> logPatterns = {
				"(%D %T): %v",
				"{\"Date-Time\": \"%D%T\", \"ProcessID\": %P, \"Thread №\": %t, \"Message\": \"%v\"},"
			};
		};
			//clang-format on
	};
} // namespace tools
} // namespace fallow
#endif // Fallow_Logger_Hpp