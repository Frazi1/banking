#pragma once
#include "stdafx.h"
#include "BankAccount.h"
#include "CustomerAccount.h"
#include <memory>
#include <functional>

using namespace std;
class bank_account;
class customer_account;

class bank
{
private:
	string name_;
	int customers_count_ = 0;
	bank_account* account_;
	vector<customer_account*> customer_accounts_{};

public:
	bank(double, float, string);
	~bank();

	string get_name() const;
	double get_savings() const;
	vector<customer_account*>& get_customer_accounts();

	void create_customer_account(const string name, customer_type type);
	void delete_customer_account(function<bool(customer_account*)> predicate);
	
	void put_money(long, double);
	void transfer_money(account_base* source, account_base* destination, const double amount);
	void accept_transfer(const double amount) const;
};
