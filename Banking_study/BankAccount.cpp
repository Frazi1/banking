#include "stdafx.h"

bank_account::bank_account(long id, bank* bank): savings_(0), bank_(bank)
{
	id_ = id;
	commission_ = 0.1f;
}

bank_account::~bank_account()
= default;

long bank_account::get_id() const
{
	return id_;
}

void bank_account::set_id(const long& id)
{
	id_ = id;
}

double bank_account::get_savings() const
{
	return savings_;
}

bank* bank_account::get_bank() const
{
	return bank_;
}

double bank_account::withdraw(const double amount)
{
	return withdraw_internal(amount);
}

double bank_account::withdraw_internal(const double amount)
{
	check_withdraw_amount(amount);
	savings_ -= amount;
	return amount;
}

void bank_account::check_withdraw_amount(const double amount) const
{
	if (amount <= 0)
		throw banking_exception(string_formatter::format("Can not withdraw %f", amount));

	if (amount > savings_)
		throw banking_exception(string_formatter::format("Account %s has only %f available. You tried to withdraw %f", id_,
		                                                 get_savings(), amount));
}

bool bank_account::can_withdraw(const double amount) const
{
	return savings_ >= amount;
}

void bank_account::put_internal(const double amount)
{
	if (amount <= 0)
		throw banking_exception(string_formatter::format("Can not put %f", amount));

	savings_ += amount;
}

void bank_account::put(const double amount)
{
	put_internal(amount);
}