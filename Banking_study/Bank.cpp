#include "stdafx.h"
#include "Bank.h"

bank::bank(const string name): name_(name), account_(bank_account(name))
{
}

bank::~bank()
{
}

string bank::get_name() const
{
	return name_;
}

vector<customer_account> bank::get_customer_accounts() const
{
	return customer_accounts_;
}

inline void bank::add_customer_account(customer_account customer_account)
{
	customer_account.set_id(std::to_string(customers_count_++));
	customer_accounts_.push_back(customer_account);
}

void bank::create_customer_account(const string name)
{
	customer c = customer(name);
	const customer_account ca = customer_account(c, std::to_string(customers_count_++), account_);
	add_customer_account(ca);
}
