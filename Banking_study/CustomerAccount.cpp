#include "stdafx.h"
#include "CustomerAccount.h"


customer_account::customer_account(const string customer_name, const string id, bank_account& parent) 
	: bank_account(id), parent_(parent), customer_name_(customer_name)
{
}


customer_account::~customer_account()
{
}

double customer_account::withdraw(const double amount) 
{
	const double withdrawed = withdraw_internal(amount);
	parent_.withdraw(withdrawed);
	return withdrawed;
}

void customer_account::transfer_to(bank_account& targetAccount, const double amount)
{
	const double withdrawed = withdraw(amount);
	parent_.transfer_to(targetAccount, withdrawed);
}
