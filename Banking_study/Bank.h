#pragma once
#include "stdafx.h"
#include "BankAccount.h"
#include "CustomerAccount.h"
#include <memory>

using namespace std;
class bank_account;
class customer_account;

class bank
{
private:
	string name_;
	int customers_count_ = 0;
	bank_account* account_;
	vector<customer_account> customer_accounts_{};
	vector<customer_account> test_vec_{};

public:
	 bank(string);
	~bank();


	string get_name() const;
	double get_savings() const;
	vector<customer_account>& get_customer_accounts();
	void create_customer_account(string name);
	void put_money(long, double);
	void transfer_money(auto_ptr<customer_account>, auto_ptr<customer_account>, double);
};