#include "stdafx.h"
#include "Bank.h"
#include "MenuHelper.h"
#include "StringFormatter.h"

bank::bank(const string name): name_(name)
{
	account_ = new bank_account(name, this);
}

bank::~bank()
= default;

string bank::get_name() const
{
	return name_;
}

double bank::get_savings() const
{
	return account_->get_savings();
}

vector<customer_account>& bank::get_customer_accounts()
{
	return customer_accounts_;
}

void bank::create_customer_account(const string name)
{
	const customer_account ca = customer_account(customer(name), std::to_string(customers_count_++), this);
	customer_accounts_.push_back(ca);
}