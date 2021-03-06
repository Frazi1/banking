#include "stdafx.h"
#include <algorithm>
#include <memory>

bank::bank(const double savings, const float comission, const string name): name_(name)
{
	account_ = make_shared<bank_account>(savings, comission, shared_ptr<bank>(this));
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

void bank::create_customer_account(const string name, customer_type type)
{
	customer c = customer(name);
	shared_ptr<bank> bank_ptr = shared_ptr<bank>(this);
	shared_ptr<customer_account> ca;
	if (type == customer_type::physical)
		ca = make_shared<physical_customer_account>(0, c, customers_count_++, bank_ptr);
	else if(type == customer_type::juridic)
		ca = make_shared<juridic_customer_account>(0, c, customers_count_++, bank_ptr);
	else throw banking_exception("Invalid customer type");
	customer_accounts_.push_back(ca);
}

void bank::put_money(long customer_id, const double amount)
{
	//TODO: maybe reference?
	const auto it = find_if(
		customer_accounts_.begin(), customer_accounts_.end(),
		[&customer_id](shared_ptr<customer_account> a)
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

void bank::transfer_money(shared_ptr<account_base> source, shared_ptr<account_base> destination, const double amount)
{
	if (source->get_bank().get() != this)
		throw banking_exception(string_formatter::format("Account %s does not belong to bank %s",
		                                                 source->get_account_name().c_str(),
		                                                 get_name().c_str()));

	const double withdrawed = source->withdraw(amount);
	const double comission = withdrawed * account_->get_comission();
	const double result_amount = withdrawed - comission;
	if (this != destination->get_bank().get())
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
