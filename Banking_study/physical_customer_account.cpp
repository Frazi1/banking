﻿#include "stdafx.h"

physical_customer_account::physical_customer_account(const double savings,
                                                     const customer customer,
                                                     const long id,
                                                     const shared_ptr<bank> bank)
	: customer_account(savings, customer, id, bank)
{
}

void physical_customer_account::transfer(const shared_ptr<account_base> target_account, const double amount)
{
	if (target_account->get_bank() != get_bank())
		throw banking_exception(
			string_formatter::format("Customer does not have permissions to transfer money to another bank"));
	customer_account::transfer(target_account, amount);
}
