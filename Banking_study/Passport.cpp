#include "stdafx.h"
#include "Passport.h"

passport::passport(int number, int series, const string place, time_t date): number_(number),
                                                                             series_(series),
                                                                             registration_place_(place),
                                                                             registration_date_(date)
{
}

int passport::get_number() const
{
	return number_;
}

int passport::get_series() const
{
	return series_;
}

string passport::get_place() const
{
	return registration_place_;
}

time_t passport::get_date() const
{
	return registration_date_;
}

string passport::get_full_info() const
{
	return string_formatter::format("%d %d %s %s", get_series(), get_number(), get_place(), get_date());
}
