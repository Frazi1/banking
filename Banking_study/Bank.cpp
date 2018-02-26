#include "stdafx.h"
#include "Bank.h"

Bank::Bank(string name): account(BankAccount(name))
{
}

Bank::~Bank()
{
}

void Bank::AddCustomer(const CustomerAccount & customer)
{
	_customerAccounts.push_back(customer);
}
