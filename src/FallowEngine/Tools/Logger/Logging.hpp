#ifndef Logging_Hpp
#define Logging_Hpp

#include "LogStyle.hpp"
#include "LogBehavior.hpp"

#include <memory>

namespace Logs {
	class Logging
	{
		Logging(std::unique_ptr<LogStyle> style);

		Logging(const Logging&) = delete;
		Logging& operator=(const Logging&) = delete; 
	private:
		std::unique_ptr<LogStyle> logStyle;
	};
}
#endif // Logging_Hpp
