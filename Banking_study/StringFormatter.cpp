#include "stdafx.h"
#include "StringFormatter.h"
#include <cstdarg>  // For va_start, etc.
#include <memory>    // For std::unique_ptr

string_formatter::string_formatter()
{
}


string_formatter::~string_formatter()
{
}

std::string string_formatter::format(const std::string fmt_str, ...) {
	int n = static_cast<int>(fmt_str.size()) * 2; /* Reserve two times as much as the length of the fmt_str */
	std::unique_ptr<char[]> formatted;
	va_list ap;
	while (true) {
		formatted.reset(new char[n]); /* Wrap the plain char array into the unique_ptr */
#pragma warning(suppress : 4996)
		strcpy(&formatted[0], fmt_str.c_str());
		va_start(ap, fmt_str);
		const int final_n = vsnprintf(&formatted[0], n, fmt_str.c_str(), ap);
		va_end(ap);
		if (final_n < 0 || final_n >= n)
			n += abs(final_n - n + 1);
		else
			break;
	}
	return std::string(formatted.get());
}