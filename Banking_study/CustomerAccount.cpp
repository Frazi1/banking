#include "stdafx.h"
#include "CustomerAccount.h"


CustomerAccount::CustomerAccount(string id, BankAccount& parent) 
	: BankAccount(id), _parent(parent)
{
}


CustomerAccount::~CustomerAccount()
{
}

double CustomerAccount::Withdraw(const double amount) 
{
	const double withdrawed = WithdrawInternal(amount);
	_parent.Withdraw(withdrawed);
	return withdrawed;
}

void CustomerAccount::TransferTo(BankAccount& targetAccount, const double amount)
{
	const double withdrawed = Withdraw(amount);
	_parent.TransferTo(targetAccount, withdrawed);
}
