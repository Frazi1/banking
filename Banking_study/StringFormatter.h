#include <string>

#pragma once
class StringFormatter
{
public:
	StringFormatter();
	~StringFormatter();
	static std::string Format(const std::string fmt_str, ...);
};

