#pragma once
#include "stdafx.h"

class juridic_customer_account : public customer_account
{
public:
	juridic_customer_account(double savings, customer customer, long id, shared_ptr<bank> bank);
};

