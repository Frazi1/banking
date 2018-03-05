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

	
	void check_withdraw_amount(double amount) const;

public:
	bank_account(long id, bank* bank);

	virtual ~bank_account();

	long  get_id() const;
	double get_savings() const;
	double get_comission() const;
	bank* get_bank() const;
	
	void set_id(const long& id);
	bool can_withdraw(double amount) const;
	double withdraw(double amount);
	void put(double amount);
	void transfer(bank_account& target_account, double amount);
	virtual void accept_transfer(double amount);
	virtual string get_account_name() const;
};