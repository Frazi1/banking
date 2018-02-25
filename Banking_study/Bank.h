#pragma once
#include "stdafx.h"
#include "BankAccount.h"
#include "CustomerAccount.h"

using namespace std;

class Bank
{
private:
	string _name;
	BankAccount account;
	vector<CustomerAccount> _customerAccounts;

public:
	Bank(string name);
	~Bank();

	void AddCustomer(const CustomerAccount& customer);
};