#pragma once
#include "stdafx.h";

class juridic_customer : public customer
{
	string inn_{};
	string ogrnip_{};
	time_t registration_date_{};
	string registration_place_{};
	string hometown_{};
	string organisation_name_{};
	string organisation_type_{};
public:

	juridic_customer(string inn,
	                 string ogrnip,
	                 time_t registration_date,
	                 string registration_place,
	                 string hometown,
	                 string organisation_name,
	                 string organisation_type);

	string get_full_info() const override;
};