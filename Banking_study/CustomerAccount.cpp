#include "stdafx.h"
#include "CustomerAccount.h"


CustomerAccount::CustomerAccount(string id, BankAccount& parent) 
	: BankAccount(id), _parent(parent)
{
}


CustomerAccount::~CustomerAccount()
{
}

double CustomerAccount::Withdraw(double amount) 
{
	double withdrawed = WithdrawInternal(amount);
	_parent.Withdraw(withdrawed);
	return withdrawed;
}

void CustomerAccount::TransferTo(BankAccount& targetAccount, double amount)
{
	double withdrawed = Withdraw(amount);
	_parent.TransferTo(targetAccount, withdrawed);
}
