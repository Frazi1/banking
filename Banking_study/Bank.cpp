#include "stdafx.h"
#include "Bank.h"
#include "MenuHelper.h"
#include "StringFormatter.h"

bank::bank(const string name): name_(name), account_(bank_account(name))
{
}

bank::~bank()
{
	menu_helper::print_string(string_formatter::format("destruct bank: %s", name_));
}

string bank::get_name() const
{
	return name_;
}

const vector<customer_account>& bank::get_customer_accounts() const
{
	return customer_accounts_;
}

void bank::create_customer_account(const string name)
{
	const customer_account ca = customer_account(customer(name), std::to_string(customers_count_++), account_);
	customer_accounts_.push_back(ca);
}