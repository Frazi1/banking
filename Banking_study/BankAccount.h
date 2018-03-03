#pragma once
#include "stdafx.h";

class bank;
using namespace std;

class bank_account
{
protected: 
	long id_;
	double savings_;
	float commission_;
	bank* bank_;

	bool can_withdraw(double amount) const;
	void put_internal(double);
	double withdraw_internal(double amount);

	void check_withdraw_amount(double amount) const;

public:
	bank_account(long id, bank* bank);

	virtual ~bank_account();

	long  get_id() const;
	double get_savings() const;
	bank* get_bank() const;
	
	void set_id(const long& id);

	virtual double withdraw(double amount);
	virtual void put(double amount);
};