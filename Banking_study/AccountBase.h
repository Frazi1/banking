#pragma once

#include "stdafx.h"

using namespace std;

class bank;
class bank_account;

class account_base
{
protected:
	double savings_;
	bank* bank_;

	void check_withdraw_amount(double amount) const;

public:
	account_base(double, bank* bank);
	virtual ~account_base() = default;

	double get_savings() const;
	bank* get_bank() const;

	bool can_withdraw(double amount) const;
	double withdraw(double amount);
	void put(double amount);

	virtual string get_account_name() const = 0;
	virtual void transfer(account_base* target_account, double amount) = 0;
	virtual void accept_transfer(double amount) = 0;
};
