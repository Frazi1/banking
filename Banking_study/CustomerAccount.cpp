#include "stdafx.h"
#include "CustomerAccount.h"
#include "MenuHelper.h"


customer_account::customer_account(const customer customer, const string id, bank* bank)
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
