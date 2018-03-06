#pragma once

#include "stdafx.h"
#include <memory>

using namespace std;

class bank;
class bank_account;

class account_base
{
protected:
	double savings_;
	shared_ptr<bank> bank_;

	void check_withdraw_amount(double amount) const;

public:
	virtual ~account_base() = default;
	account_base(const double savings, shared_ptr<bank> bank);

	double get_savings() const;
	shared_ptr<bank> get_bank() const;

	bool can_withdraw(double amount) const;
	double withdraw(double amount);
	void put(double amount);

	virtual string get_account_name() const = 0;
	virtual void transfer(shared_ptr<account_base> target_account, double amount) = 0;
	virtual void accept_transfer(double amount) = 0;
};
