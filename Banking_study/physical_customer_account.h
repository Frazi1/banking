#pragma once
#include "stdafx.h"

class physical_customer_account : public customer_account
{
public:
	physical_customer_account(double savings, customer customer, long id, shared_ptr<bank> bank);

	void transfer(shared_ptr<account_base> target_account, double amount) override;
};
