#include "stdafx.h"

customer_account::customer_account(const double savings, const customer customer, const long id,
                                   const shared_ptr<bank> bank)
	: account_base(savings, bank), customer_(customer), id_(id)
{
}

customer customer_account::get_customer() const
{
	return customer_;
}

long customer_account::get_id() const
{
	return id_;
}


void customer_account::set_customer(const customer customer)
{
	customer_ = customer;
}

void customer_account::accept_transfer(const double amount)
{
	//TODO:
	put(amount);
	bank_->accept_transfer(amount);
}

void customer_account::transfer(shared_ptr<account_base> target_account, const double amount)
{
	const shared_ptr<customer_account> account = shared_ptr<customer_account>(this);
	get_bank()->transfer_money(account, target_account, amount);
}

string customer_account::get_account_name() const
{
	return get_customer().get_customer_name();
}