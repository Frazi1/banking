#pragma once
#include "stdafx.h"

class bank;

enum class customer_type 
{ 
	physical = 1,
	juridic = 2
};

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
	virtual void transfer(shared_ptr<account_base> target_account, const double amount) override;
	string get_account_name() const override;
};

class juridic_customer_account : public customer_account
{
public:
	juridic_customer_account(double savings, customer customer, long id, shared_ptr<bank> bank);
};

class physical_customer_account : public customer_account
{
public:
	physical_customer_account(double savings, customer customer, long id, shared_ptr<bank> bank);

	void transfer(shared_ptr<account_base> target_account, double amount) override;
};
