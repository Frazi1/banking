#pragma once
#include "stdafx.h";

class bank;
using namespace std;

class bank_account
{
protected: 
	string id_;
	double savings_;
	float commission_;

	bool can_withdraw(double amount) const;
	void put_internal(double);
	double withdraw_internal(double amount);

	void check_withdraw_amount(double amount) const;

public:
	bank_account(string id, bank* bank);
	virtual ~bank_account();

	string get_id() const;
	void set_id(const string& id);
	double get_savings() const;

	virtual double withdraw(double amount);
	virtual void put(double amount);
	virtual void transfer_to(bank_account& target_account, double amount);
};