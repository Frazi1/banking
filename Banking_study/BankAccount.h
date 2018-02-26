#pragma once
#include <string>

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
	virtual ~BankAccount();
	string GetId();
	double GetSavings();
	virtual double Withdraw(double amount);
	virtual void Put(double amount);
	virtual void TransferTo(BankAccount& targetAccount, double amount);
};

