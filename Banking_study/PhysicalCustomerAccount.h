﻿#pragma once
#include "stdafx.h"

class physical_customer;

class physical_customer_account : public customer_account
{
public:
	physical_customer_account(double, physical_customer*, long, bank* bank);
	void transfer(account_base* target_account, double amount) override;
};
