#pragma once
#include "stdafx.h"
#include "BankAccount.h"
#include "CustomerAccount.h"

using namespace std;

class bank
{
private:
	string name_;
	int customers_count_ = 0;
	bank_account account_;
	vector<customer_account> customer_accounts_;

public:
	bank(string name);
	~bank();

	string get_name() const;
	vector<customer_account> get_customer_accounts() const;
	void add_customer_account(customer_account customer_account);
	void create_customer_account(string name);
};