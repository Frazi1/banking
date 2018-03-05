#include "stdafx.h"
#include <algorithm>
#include <memory>

bank::bank(const string name): name_(name)
{
	account_ = new bank_account(0, this);
}

bank::~bank()
= default;

string bank::get_name() const
{
	return name_;
}

double bank::get_savings() const
{
	return account_->get_savings();
}

vector<shared_ptr<customer_account>>& bank::get_customer_accounts()
{
	return customer_accounts_;
}

void bank::create_customer_account(const string name)
{
	const auto ca = make_shared<customer_account>(customer(name), customers_count_++, this);
	customer_accounts_.push_back(ca);
}

void bank::put_money(long customer_id, const double amount)
{
	//TODO: maybe reference?
	const auto it = find_if(
		customer_accounts_.begin(), customer_accounts_.end(),
		[&customer_id](shared_ptr<customer_account>& a)
		{
			return a->get_id() == customer_id;
		});

	if (it == customer_accounts_.end())
		throw banking_exception(string_formatter::format("customer account %s does not belong to bank %s",
		                                                 customer_id, get_name().c_str()));

	const auto index = distance(customer_accounts_.begin(), it);

	account_->put(amount);
	customer_accounts_.at(index)->put(amount);
}

void bank::transfer_money(bank_account& source, bank_account& destination, const double amount)
{
	if (source.get_bank() != this)
		throw banking_exception(string_formatter::format("fuck"));

	const double withdrawed = source.withdraw(amount);
	const double comission = withdrawed * account_->get_comission();
	const double result_amount = withdrawed - comission;
	if (this != destination.get_bank())
	{
		if (!account_->can_withdraw(withdrawed))
			throw banking_exception(string_formatter::format("Tried to withdraw %f. Bank have only %f. Sorry", withdrawed,
			                                                 account_->get_savings()));
		account_->withdraw(withdrawed);

		destination.accept_transfer(result_amount);
	}
	else
	{
		destination.put(result_amount);
	}
}

void bank::accept_transfer(const double amount) const
{
	account_->accept_transfer(amount);
}
