#include "stdafx.h"

physical_customer_account::physical_customer_account(const double savings,
                                                     physical_customer* customer,
                                                     const long id,
                                                     bank* bank)
	: customer_account(id, savings, bank), customer_(customer)
{
}

void physical_customer_account::transfer(account_base* target_account, const double amount)
{
	if (target_account->get_bank() != get_bank())
		throw banking_exception(
			string_formatter::format("Customer does not have permissions to transfer money to another bank"));
	customer_account::transfer(target_account, amount);
}

customer* physical_customer_account::get_customer() const
{
	return customer_;
}


