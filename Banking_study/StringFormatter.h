#pragma once
#include <string>

#pragma once
class string_formatter
{
public:
	string_formatter();
	~string_formatter();
	static std::string format(std::string fmt_str, ...);
};

