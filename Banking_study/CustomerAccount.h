#pragma once
#include "BankAccount.h"

class CustomerAccount : public BankAccount
{
public:
	CustomerAccount(string id, BankAccount& parent);
	~CustomerAccount();

	double Withdraw(double amount) override;
	void TransferTo(BankAccount& targetAccount, double amount) override;
private:
	BankAccount& _parent;
};


