#include "stdafx.h"
#include "PhysicalCustomer.h"
#include <iomanip>
#include <iostream>

physical_customer::physical_customer(string first_name, string last_name, const int passport_number,
                                     const int passport_series,
                                     const string registration_place, const tm registration_date)
	: passport_number_(passport_number),
	  passport_series_(passport_series),
	  registration_place_(registration_place),
	  registration_date_(registration_date),
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

tm physical_customer::get_registration_date() const
{
	return registration_date_;
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
	throw logic_error("not implemented");
}

string physical_customer::get_short_info() const
{
	tm registration_date = get_registration_date();
	cout << put_time(&registration_date, "%d/%m/%Y") << endl;
	return string_formatter::format("%s %s - %s", 
		get_first_name().c_str(),
		get_last_name().c_str(),
		put_time(&registration_date,"%d/%m/%Y"));
}

customer_type physical_customer::get_customer_type()
{
	return customer_type::physical;
}
