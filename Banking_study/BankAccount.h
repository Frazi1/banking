#pragma once
#include "stdafx.h";

using namespace std;

class bank_account : public account_base
{
protected: 
	float commission_;
public:
	bank_account(double savings, float comission, bank* bank);

	virtual ~bank_account();
	double get_comission() const;
	void transfer(account_base* target_account, const double amount) override;
	void accept_transfer(double) override;

	string get_account_name() const override;
};