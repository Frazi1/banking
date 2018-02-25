#include "stdafx.h"
#include "BankAccount.h"


BankAccount::BankAccount(string id)
{
	_id = id;
	_commission = 0.1f;
}


BankAccount::~BankAccount()
{
}

string BankAccount::GetId()
{
	return _id;
}

double BankAccount::GetSavings()
{
	return _savings;
}

double BankAccount::Withdraw(double amount)
{
	return WithdrawInternal(amount);
}

double BankAccount::WithdrawInternal(double amount)
{
	if (CanWithdraw(amount)) {
		_savings -= amount;
		return amount;
	}
	throw new BankingException(StringFormatter::Format("Account has %d available. You tried to withdraw %d", GetSavings(), amount));
}

bool BankAccount::CanWithdraw(double amount)
{
	return _savings >= amount;
}

void BankAccount::Put(double amount)
{
	_savings += amount;
}

void BankAccount::TransferTo(BankAccount& targetAccount, double amount)
{
	double transferAmount = amount - amount * _commission;
	targetAccount.Put(Withdraw(transferAmount));
}
