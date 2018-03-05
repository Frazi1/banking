#pragma once
#include "stdafx.h"

class bank;

class customer_account : public bank_account
{
private:
	customer customer_;
public:
	customer_account(customer customer, long, bank* bank);

	customer get_customer() const;
	void set_customer(customer customer);

	void accept_transfer(double amount) override;

	string get_account_name() const override;
};
