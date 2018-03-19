#pragma once
#include "stdafx.h"

class juridic_customer;

class juridic_customer_account : public customer_account
{
private:
	juridic_customer * customer_;
public:
	juridic_customer_account(double savings, juridic_customer* customer, long id, bank* bank);

	customer* get_customer() const override;
};

