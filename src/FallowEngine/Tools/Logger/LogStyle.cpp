#include "LogStyle.hpp"

namespace Logs
{
	std::string PlainStyle::getStyle() { return styledString; }
	void        PlainStyle::setStyle(LogBehavior::LogLevel level)
	{
		switch (level)
		{
			case LogBehavior::LogLevel::LOG_OFF:
				styledString = "";
				break;
			case LogBehavior::LogLevel::LOG_FATAL:
				styledString = LogColoring::FATAL;
				break;
			case LogBehavior::LogLevel::LOG_ERROR:
				styledString = LogColoring::ERROR;
				break;
			case LogBehavior::LogLevel::LOG_WARNING:
				styledString = LogColoring::WARNING;
				break;
			case LogBehavior::LogLevel::LOG_INFO:
				styledString = LogColoring::INFO;
				break;
			case LogBehavior::LogLevel::LOG_DEBUG:
				styledString = LogColoring::DEBUG;
				break;
			case LogBehavior::LogLevel::LOG_TRACE:
				styledString = LogColoring::TRACE;
				break;
		}
	}

	std::string JsonStyle::getStyle() { return styledString; }
	void        JsonStyle::setStyle(LogBehavior::LogLevel level)
	{
		styledString = LogBehavior::levelNames[LogBehavior::as_integer(level)];
	}
	std::string FileStyle::getStyle() { return styledString; }
	void        FileStyle::setStyle(LogBehavior::LogLevel level)
	{
		styledString = LogBehavior::levelNames[LogBehavior::as_integer(level)];
	}
} // namespace Logs