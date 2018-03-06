#pragma once
#include "stdafx.h"

class bank;

enum class customer_type { juridic, physical };

class customer_account : public account_base
{
private:
	long id_;
	customer customer_;
public:
	customer_account(double, customer, long, shared_ptr<bank>);
	customer get_customer() const;

	long get_id() const;
	void set_customer(customer customer);

	void accept_transfer(double amount) override;
	void transfer(shared_ptr<account_base> target_account, const double amount) override = 0;
	string get_account_name() const override;
};

class juridic_customer_account : public customer_account
{
public:
	juridic_customer_account(double savings, customer customer, long id, shared_ptr<bank> bank);

	void transfer(shared_ptr<account_base> target_account, double amount) override;
};

class physical_customer_account : public customer_account
{
public:
	physical_customer_account(double savings, customer customer, long id, shared_ptr<bank> bank);

	void transfer(shared_ptr<account_base> target_account, double amount) override;
};
