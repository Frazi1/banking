#pragma once
#include "stdafx.h"

class juridic_customer;

class juridic_customer_account : public customer_account
{
public:
	juridic_customer_account(double savings, juridic_customer* customer, long id, bank* bank);
};

