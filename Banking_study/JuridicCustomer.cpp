#include "stdafx.h"
#include "JuridicCustomer.h"

juridic_customer::juridic_customer(const string inn,
                                   const string ogrnip,
                                   const tm registration_date,
                                   const string registration_place,
                                   const string hometown,
                                   const string organisation_name,
                                   const string organisation_type)
	: inn_(inn),
	  ogrnip_(ogrnip),
	  registration_date_(registration_date),
	  registration_place_(registration_place),
	  hometown_(hometown),
	  organisation_name_(organisation_name),
	  organisation_type_(organisation_type)
{
}

string juridic_customer::get_inn() const
{
	return inn_;
}

string juridic_customer::get_ogrnip() const
{
	return ogrnip_;
}

tm juridic_customer::get_registration_date() const
{
	return registration_date_;
}

string juridic_customer::get_registration_place() const
{
	return registration_place_;
}

string juridic_customer::get_hometown() const
{
	return hometown_;
}

string juridic_customer::get_organisation_name() const
{
	return organisation_name_;
}

string juridic_customer::get_organisation_type() const
{
	return organisation_type_;
}

string juridic_customer::get_full_info() const
{
	throw logic_error("not implemented");
}

string juridic_customer::get_short_info() const
{
	return string_formatter::format("%s - %s, %s",
	                                get_organisation_name().c_str(),
	                                get_organisation_type().c_str(),
	                                get_hometown().c_str());
}

customer_type juridic_customer::get_customer_type()
{
	return customer_type::juridic;
}
