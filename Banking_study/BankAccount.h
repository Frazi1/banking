#include <string>
#include "BankingException.h"
#include "StringFormatter.h"

using namespace std;

#pragma once
class BankAccount
{

private: 
	string _id;
	double _savings;
	float _commission;

protected:
	bool CanWithdraw(double amount);
	double WithdrawInternal(double amount);

public:
	BankAccount(string id);
	~BankAccount();
	string GetId();
	double GetSavings();
	virtual double Withdraw(double amount);
	virtual void Put(double amount);
	virtual void TransferTo(BankAccount& targetAccount, double amount);
};

