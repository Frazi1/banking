#pragma once
#include "stdafx.h"

class physical_customer : public customer
{
private:
	int passport_number_;
	int passport_series_;
	string registration_place_{};
	tm birthday_date{};
	string first_name_{};
	string last_name_{};
public:
	physical_customer(string first_name, string last_name, int passport_number, int passport_series,
	                  string registration_place, tm registration_date);


	int get_passport_number() const;
	int get_passport_series() const;
	string get_registration_place() const;
	tm get_birthday_date() const;
	string get_first_name() const;
	string get_last_name() const;
	string get_full_info() const override;
	string get_short_info() const override;
	customer_type get_customer_type() override;
};
