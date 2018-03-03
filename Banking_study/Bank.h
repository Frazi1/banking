#pragma once
#include "stdafx.h"
#include "BankAccount.h"
#include "CustomerAccount.h"

using namespace std;
class bank_account;
class customer_account;

class bank
{
private:
	string name_;
	int customers_count_ = 0;
	bank_account *account_;
	vector<customer_account> customer_accounts_{};

public:
	explicit bank(string);
	~bank();

	string get_name() const;
	double get_savings() const;
	vector<customer_account>& get_customer_accounts();
	void create_customer_account(string name);
};