#include "stdafx.h"
#include "CustomerAccount.h"
#include "MenuHelper.h"

customer_account::customer_account(const customer customer, const long id, bank* bank)
	: bank_account(id, bank), customer_(customer)
{
}

customer customer_account::get_customer() const
{
	return customer_;
}


void customer_account::set_customer(const customer customer)
{
	customer_ = customer;
}

void customer_account::accept_transfer(const double amount)
{
	put(amount);
	bank_->accept_transfer(amount);
}

string customer_account::get_account_name() const
{
	return get_customer().get_customer_name();
}
