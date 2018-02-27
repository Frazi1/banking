#include "stdafx.h"
#include "Bank.h"

bank::bank(const string name): account_(bank_account(name)), name_(name)
{
}

bank::~bank()
{
}

string bank::get_name()
{
	return name_;
}

vector<customer_account> bank::get_customer_accounts()
{
	return customer_accounts_;
}

void bank::add_customer(const customer_account & customer)
{
	customer_accounts_.push_back(customer);
}
