#pragma once
#include "stdafx.h";

class juridic_customer : public customer
{
	string inn_{};
	string ogrnip_{};
	tm registration_date_{};
	string registration_place_{};
	string hometown_{};
	string organisation_name_{};
	string organisation_type_{};
public:

	juridic_customer(string inn,
	                 string ogrnip,
	                 tm registration_date,
	                 string registration_place,
	                 string hometown,
	                 string organisation_name,
	                 string organisation_type);


	string get_inn() const;
	string get_ogrnip() const;
	tm get_registration_date() const;
	string get_registration_place() const;
	string get_hometown() const;
	string get_organisation_name() const;
	string get_organisation_type() const;
	string get_full_info() const override;
	string get_short_info() const override;
	customer_type get_customer_type() override;
};