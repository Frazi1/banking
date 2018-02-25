#include "Bank.h"

Bank::Bank(string name)
{
}

Bank::~Bank()
{
}

void Bank::AddCustomer(const CustomerAccount & customer)
{
	_customerAccounts.push_back(customer);
}
