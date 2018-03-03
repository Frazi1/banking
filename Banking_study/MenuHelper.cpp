#include "stdafx.h"
#include "MenuHelper.h"
#include <iostream>
#include "Bank.h"
#include "StringFormatter.h"

using namespace std;


menu_helper::menu_helper(const vector<bank> banks) : banks_(banks)
{
}

void menu_helper::process_input()
{
	int input;
	cin >> input;

	switch (input)
	{
	case 1:
		add_bank();
		break;
	case 2:
		print_banks(banks_);
		break;
	case 3:
		create_customer_account();
		break;
	case 4:
		print_bank_customer_accounts();
		break;
	case 5:
		print_customer_money();
		break;
	case 6:
		put_customer_money();
		break;
	case 7:
		print_bank_money();
		break;
	case 8:
		transfer_money_to_other_customer();
		break;
	}
}

void menu_helper::print_menu()
{
	std::vector<string> items;
	items.push_back("1. Add bank");
	items.push_back("2. Print banks");
	items.push_back("3. Create bank customer");
	items.push_back("4. Print bank customers");
	items.push_back("5. Print customer money");
	items.push_back("6. Put money");
	items.push_back("7. Print bank money");
	items.push_back("8. Transfer money");


	for (const string item : items)
		print_string(item);
}

string menu_helper::read_string()
{
	string s;
	std::cin >> s;
	return s;
}

int menu_helper::read_int()
{
	return stoi(read_string());
}


double menu_helper::read_double()
{
	return stod(read_string());
}

void menu_helper::put_customer_money()
{
	bank& bank = select_bank();
	const auto customer_account = select_customer_account(bank);
	const double amount = read_double();
	bank.put_money(customer_account->get_id(), amount);
}

void menu_helper::transfer_money_to_other_customer()
{
	//TODO:
	//bank& source_bank = select_bank("select source bank\n");
	//customer_account& source_customer = select_customer_account(source_bank, "select source customer\n");

	//bank& destination_bank = select_bank("select destination bank\n");
	//customer_account& destination_customer = select_customer_account(destination_bank, "select destination customer\n");

	//const double amount = select_amount();
	//source_customer.transfer_to(destination_customer, amount);
}

bank& menu_helper::select_bank(const string display_message)
{
	print_string(display_message);
	print_banks(banks_);
	return banks_[read_int()];
}

shared_ptr<customer_account> menu_helper::select_customer_account(bank& bank, const string display_message) const
{
	print_string(display_message);
	print_customers(bank);
	const int index = read_int();
	auto ca = bank.get_customer_accounts();
	const shared_ptr<customer_account> customer_account = ca.at(index);
	return customer_account;
}

double menu_helper::select_amount() const
{
	print_string("select amount\n");
	return read_double();
}

void menu_helper::add_bank()
{
	print_string("define bank name");
	const string name = read_string();
	const bank a = bank(name);
	banks_.push_back(a);
}

void menu_helper::print_banks(vector<bank>& banks)
{
	for (int i = 0; i < banks.size(); i++)
	{
		string bank_name = banks[i].get_name();
		print_string(string_formatter::format("%d.%s", i, bank_name.c_str()));
	}
}

void menu_helper::print_bank_customer_accounts()
{
	bank& bank = select_bank();
	print_customers(bank);
}

void menu_helper::print_customer_money()
{
	bank& bank = select_bank();
	const auto customer_account = select_customer_account(bank);
	const double savings = customer_account->get_savings();
	print_string(string_formatter::format("Customer has: %f", savings));
}

void menu_helper::print_bank_money()
{
	bank& bank = select_bank();
	const double savings = bank.get_savings();
	print_string(string_formatter::format("Bank has: %f", savings));
}

void menu_helper::print_string(const string str)
{
	std::cout << str << endl;
}

void menu_helper::print_string()
{
	std::cout << endl;
}


void menu_helper::print_customers(bank& bank)
{
	auto customer_accounts = bank.get_customer_accounts();
	for (int i = 0; i < customer_accounts.size(); i++)
	{
		const auto customer_account = customer_accounts.at(i);
		print_string(string_formatter::format("%d.%s",
		                                      i,
		                                      customer_account->get_customer().get_customer_name().c_str()));
	}
}

void menu_helper::create_customer_account()
{
	bank& bank = select_bank();

	print_string("customer name:");
	bank.create_customer_account(read_string());
}
