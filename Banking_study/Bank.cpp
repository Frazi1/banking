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

vector<customer_account>& bank::get_customer_accounts()
{
	return customer_accounts_;
}

void bank::create_customer_account(const string name)
{
	const auto ca = customer_account(customer(name), customers_count_++, this);
	customer_accounts_.push_back(ca);
}

void bank::put_money(long customer_id, const double amount)
{
	const auto it = find_if(
		customer_accounts_.begin(), customer_accounts_.end(),
		[&customer_id](customer_account a)
		{
			return a.get_id() == customer_id;
		});

	if (it == customer_accounts_.end())
		throw banking_exception(string_formatter::format("customer account %s does not belong to bank %s",
		                                                 customer_id, get_name().c_str()));

	const auto index = distance(customer_accounts_.begin(), it);

	account_->put(amount);
	customer_accounts_.at(index).put(amount);
}

void bank::transfer_money(auto_ptr<customer_account> source, auto_ptr<customer_account> destination, const double amount)
{
	double withdrawed = source.get()->withdraw(amount);

}
