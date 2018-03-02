#include "stdafx.h"
#include "CustomerAccount.h"
#include "MenuHelper.h"


customer_account::customer_account(const customer customer, const string id, bank_account& parent)
	: bank_account(id), customer_(customer), parent_(parent)
{
}

customer_account::~customer_account()
{
	menu_helper::print_string("destructed customer account");
}


customer customer_account::get_customer() const
{
	return customer_;
}


void customer_account::set_customer(const customer customer)
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

void customer_account::put(const double amount)
{
	parent_.put(amount);
	put_internal(amount);
}
