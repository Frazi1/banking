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
	vector<shared_ptr<customer_account>> customer_accounts_{};

public:
	 bank(string);
	~bank();


	string get_name() const;
	double get_savings() const;
	const vector<shared_ptr<customer_account>>& get_customer_accounts() const;
	void create_customer_account(string name);
	void put_money(long, double) const;
};