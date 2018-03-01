#include "stdafx.h"
#include "BankAccount.h"
#include "BankingException.h"
#include "StringFormatter.h"

bank_account::bank_account(string id): savings_(0)
{
	id_ = id;
	commission_ = 0.1f;
}


bank_account::~bank_account()
= default;

string bank_account::get_id() const
{
	return id_;
}

void bank_account::set_id(const string& id)
{
	id_ = id;
}

double bank_account::get_savings() const
{
	return savings_;
}

double bank_account::withdraw(const double amount)
{
	return withdraw_internal(amount);
}

double bank_account::withdraw_internal(const double amount)
{
	if (can_withdraw(amount)) {
		savings_ -= amount;
		return amount;
	}
	throw new banking_exception(string_formatter::format("Account has %d available. You tried to withdraw %d", get_savings(), amount));
}

bool bank_account::can_withdraw(const double amount) const
{
	return savings_ >= amount;
}

void bank_account::put(const double amount)
{
	savings_ += amount;
}

void bank_account::transfer_to(bank_account& target_account, const double amount)
{
	const double transfer_amount = amount - amount * commission_;
	target_account.put(withdraw(transfer_amount));
}
