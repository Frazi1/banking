#include "stdafx.h"

bank_account::bank_account(const double savings, const float comission, const shared_ptr<bank> bank): account_base(savings, bank),
                                                                               commission_(comission)
{
}

bank_account::~bank_account()
= default;

double bank_account::get_comission() const
{
	return commission_;
}


void bank_account::transfer(const shared_ptr<account_base> target_account, const double amount)
{
	return bank_->transfer_money(shared_ptr<bank_account>(this), target_account, amount);
}

void bank_account::accept_transfer(const double amount)
{
	put(amount);
}

string bank_account::get_account_name() const
{
	return bank_->get_name();
}
