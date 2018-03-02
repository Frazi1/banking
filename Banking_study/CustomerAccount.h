#pragma once
#include "BankAccount.h"
#include "Customer.h"

class customer_account : public bank_account
{
private:
	customer customer_;
	bank_account& parent_;

public:
	customer_account(customer customer, string id, bank_account& parent);
	~customer_account() override;

	customer get_customer() const;
	void set_customer(customer customer);

	double withdraw(double amount) override;
	void transfer_to(bank_account& target_account, double amount) override;
};
