#pragma once
#include <string>

#pragma once
class string_formatter
{
public:
	static std::string format(std::string fmt_str, ...);
	static std::string get_date_format();
};
