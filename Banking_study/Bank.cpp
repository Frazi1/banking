#include "stdafx.h"
#include <algorithm>
#include <memory>

bank::bank(const double savings, const float comission, const string name): name_(name)
{
	account_ = new bank_account(savings, comission, this);
}

bank::~bank()
{
	delete account_;
	for (customer_account* customer_account : customer_accounts_)
		delete customer_account;
}

string bank::get_name() const
{
	return name_;
}

double bank::get_savings() const
{
	return account_->get_savings();
}

vector<customer_account*>& bank::get_customer_accounts()
{
	return customer_accounts_;
}

void bank::create_customer_account(customer* customer)
{
	customer_account* ca;
	if (customer->get_customer_type() == customer_type::physical)
		ca = new physical_customer_account(0, static_cast<physical_customer*>(customer), customers_count_++, this);
	else if (customer->get_customer_type() == customer_type::juridic)
		ca = new juridic_customer_account(0, static_cast<juridic_customer*>(customer), customers_count_++, this);
	else throw banking_exception("Invalid customer type");
	customer_accounts_.push_back(ca);
}

void bank::delete_customer_account(function<bool (customer_account*)> predicate)
{
	const auto item = find_if(customer_accounts_.begin(), customer_accounts_.end(), predicate);
	customer_account* ptr = customer_accounts_.at(distance(customer_accounts_.begin(), item));
	customer_accounts_.erase(remove_if(customer_accounts_.begin(),
	                                   customer_accounts_.end(),
	                                   predicate),
	                         customer_accounts_.end());
	customers_count_--;
	delete ptr;
}

void bank::put_money(long customer_id, const double amount)
{
	const auto it = find_if(
		customer_accounts_.begin(), customer_accounts_.end(),
		[&customer_id](customer_account* a)
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

void bank::transfer_money(account_base* source, account_base* destination, const double amount)
{
	if (source->get_bank() != this)
		throw banking_exception(string_formatter::format("Account %s does not belong to bank %s",
		                                                 source->get_account_name().c_str(),
		                                                 get_name().c_str()));

	const double withdrawed = source->withdraw(amount);
	const double comission = withdrawed * account_->get_comission();
	const double result_amount = withdrawed - comission;
	if (this != destination->get_bank())
	{
		if (!account_->can_withdraw(withdrawed))
			throw banking_exception(string_formatter::format("Tried to withdraw %f. Bank has only %f. Sorry",
			                                                 withdrawed,
			                                                 account_->get_savings()));
		account_->withdraw(withdrawed);

		destination->accept_transfer(result_amount);
	}
	else
	{
		destination->put(result_amount);
	}
}

void bank::accept_transfer(const double amount) const
{
	account_->accept_transfer(amount);
}
