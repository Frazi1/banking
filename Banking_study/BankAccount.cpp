#include "stdafx.h"
#include "BankAccount.h"
#include "BankingException.h"
#include "StringFormatter.h"

BankAccount::BankAccount(string id): _savings(0)
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

double BankAccount::WithdrawInternal(const double amount)
{
	if (CanWithdraw(amount)) {
		_savings -= amount;
		return amount;
	}
	throw new BankingException(StringFormatter::Format("Account has %d available. You tried to withdraw %d", GetSavings(), amount));
}

bool BankAccount::CanWithdraw(const double amount)
{
	return _savings >= amount;
}

void BankAccount::Put(const double amount)
{
	_savings += amount;
}

void BankAccount::TransferTo(BankAccount& targetAccount, const double amount)
{
	const double transferAmount = amount - amount * _commission;
	targetAccount.Put(Withdraw(transferAmount));
}
