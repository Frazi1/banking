#include "stdafx.h"


account_base::account_base(const double savings, bank* bank): savings_(savings),
                                                              bank_(bank)
{
}

double account_base::get_savings() const
{
	return savings_;
}

bank* account_base::get_bank() const
{
	return bank_;
}

void account_base::check_withdraw_amount(const double amount) const
{
	if (amount <= 0)
		throw banking_exception(string_formatter::format("Can not withdraw %f", amount));

	if (amount > savings_)
		throw banking_exception(string_formatter::format("Account %s has only %f available. You tried to withdraw %f",
			get_account_name().c_str(),
			get_savings(), amount));
}

double account_base::withdraw(const double amount)
{
	check_withdraw_amount(amount);
	savings_ -= amount;
	return amount;
}

bool account_base::can_withdraw(const double amount) const
{
	return savings_ >= amount;
}

void account_base::put(const double amount)
{
	if (amount <= 0)
		throw banking_exception(string_formatter::format("Can not put %f", amount));

	savings_ += amount;
}

