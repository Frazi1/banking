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
	shared_ptr<bank_account> account_;
	vector<shared_ptr<customer_account>> customer_accounts_{};

public:
	bank(double, float, string);
	~bank();


	string get_name() const;
	double get_savings() const;
	vector<shared_ptr<customer_account>>& get_customer_accounts();
	void create_customer_account(const string name, customer_type type);
	void put_money(long, double);
	void transfer_money(shared_ptr<account_base> source, shared_ptr<account_base> destination, const double amount);
	void accept_transfer(const double amount) const;
};
