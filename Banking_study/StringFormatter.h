#pragma once
#include <string>

#pragma once
class string_formatter
{
public:
	static std::string format(std::string fmt_str, ...);
	static std::string date_to_str(std::tm);
};
