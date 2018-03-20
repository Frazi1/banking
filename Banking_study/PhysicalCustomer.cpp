#include "stdafx.h"
#include "PhysicalCustomer.h"
#include <iomanip>

physical_customer::physical_customer(const string first_name,
                                     const string last_name,
                                     const int passport_number,
                                     const int passport_series,
                                     const string registration_place,
                                     const tm birthday_date)
	: passport_number_(passport_number),
	  passport_series_(passport_series),
	  registration_place_(registration_place),
	  birthday_date(birthday_date),
	  first_name_(first_name),
	  last_name_(last_name)
{
}

int physical_customer::get_passport_number() const
{
	return passport_number_;
}

int physical_customer::get_passport_series() const
{
	return passport_series_;
}

string physical_customer::get_registration_place() const
{
	return registration_place_;
}

tm physical_customer::get_birthday_date() const
{
	return birthday_date;
}

string physical_customer::get_first_name() const
{
	return first_name_;
}

string physical_customer::get_last_name() const
{
	return last_name_;
}

string physical_customer::get_full_info() const
{
	return string_formatter::format("%s %s %s, passport: %d %d, registration place:%s ",
	                                get_first_name().c_str(),
	                                get_last_name().c_str(),
	                                string_formatter::date_to_str(get_birthday_date()).c_str(),
	                                get_passport_series(),
	                                get_passport_number(),
	                                get_registration_place().c_str());
}

string physical_customer::get_short_info() const
{
	return string_formatter::format("%s %s - %s",
	                                get_first_name().c_str(),
	                                get_last_name().c_str(),
	                                string_formatter::date_to_str(get_birthday_date()).c_str());
}

customer_type physical_customer::get_customer_type()
{
	return customer_type::physical;
}
