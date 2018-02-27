#pragma once
#include "stdafx.h"
#include "BankAccount.h"
#include "CustomerAccount.h"

using namespace std;

class bank
{
private:
	string name_;
	bank_account account_;
	vector<customer_account> customer_accounts_;

public:
	bank(string name);
	~bank();

	string get_name();
	vector<customer_account> get_customer_accounts();
	void add_customer(const customer_account& customer);
};