#pragma once
#include "stdafx.h"
#include "Customer.h"

class customer;
class bank;

enum class customer_type 
{ 
	physical = 1,
	juridic = 2
};

class customer_account : public account_base
{
	long id_;
public:
	customer_account(long id, double savings, bank* bank);
	virtual customer* get_customer() const = 0;

	long get_id() const;
	void set_id(const long id);
	
	void accept_transfer(double amount) override;
	virtual void transfer(account_base* target_account, const double amount) override;
	string get_account_name() const override;
};