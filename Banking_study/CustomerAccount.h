#pragma once
#include "BankAccount.h"

class customer_account : public bank_account
{
private:
	bank_account & parent_;
	string customer_name_;
public:
	customer_account(string customer_name, string id, bank_account& parent);
	~customer_account();

	double withdraw(double amount) override;
	void transfer_to(bank_account& targetAccount, double amount) override;
};


