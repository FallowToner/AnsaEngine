#ifndef Log_Style_Hpp
#define Log_Style_Hpp

#include <array>
#include <string>

#include "LogBehavior.hpp"

namespace Logs
{
	class LogStyle
	{
	public:
		virtual ~LogStyle() = default;

		virtual std::string getStyle()                            = 0;
		virtual void        setStyle(LogBehavior::LogLevel level) = 0;

		std::string styledString;
	};

	class PlainStyle : public LogStyle
	{
	public:
		virtual ~PlainStyle() = default;

		virtual std::string getStyle() override;
		virtual void        setStyle(LogBehavior::LogLevel level) override;

	private:
		struct LogColoring
		{
			inline static constexpr const char* INFO    = "\033[1;32m[INFO]\033[0m";
			inline static constexpr const char* TRACE   = "\033[1;96m[TRACE]\033[0m";
			inline static constexpr const char* DEBUG   = "\033[1;36m[DEBUG]\033[0m";
			inline static constexpr const char* WARNING = "\033[1;93m[WARNING]\033[0m";
			inline static constexpr const char* ERROR   = "\033[1;31m[ERROR]\033[0m";
			inline static constexpr const char* FATAL   = "\033[1;91m[FATAL]\033[0m";
		};
	};

	class JsonStyle : public LogStyle
	{
	public:
		virtual ~JsonStyle() = default;

		virtual std::string getStyle() override;
		virtual void        setStyle(LogBehavior::LogLevel level) override;
	};

	class FileStyle : public LogStyle
	{
	public:
		virtual ~FileStyle() = default;

		virtual std::string getStyle() override;
		virtual void        setStyle(LogBehavior::LogLevel level) override;
	};
} // namespace Logs

#endif // Log_Style_Hpp