#include "stdafx.h"
#include "CustomerAccount.h"


customer_account::customer_account(customer& customer, const string id, bank_account& parent)
	: bank_account(id), customer_(customer), parent_(parent)
{
}

customer_account::~customer_account()
= default;


customer& customer_account::get_customer() const
{
	return customer_;
}


void customer_account::set_customer(const customer& customer) const
{
	customer_ = customer;
}

double customer_account::withdraw(const double amount)
{
	const double withdrawed = withdraw_internal(amount);
	parent_.withdraw(withdrawed);
	return withdrawed;
}

void customer_account::transfer_to(bank_account& target_account, const double amount)
{
	const double withdrawed = withdraw(amount);
	parent_.transfer_to(target_account, withdrawed);
}
