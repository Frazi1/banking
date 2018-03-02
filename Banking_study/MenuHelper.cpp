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
		add_bank(banks_);
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
	customer_account& customer_account = select_customer_account(bank);
	const double amount = read_double();
	customer_account.put(amount);
}

bank& menu_helper::select_bank()
{
	print_string("select bank\n");
	print_banks(banks_);
	return banks_[read_int()];
}

customer_account& menu_helper::select_customer_account(bank& bank) const
{
	print_string("select customer account\n");
	print_customers(bank);
	customer_account& customer_account = bank.get_customer_accounts()[read_int()];
	return customer_account;
}

void menu_helper::add_bank(vector<bank>& banks)
{
	const string name = read_string();
	const bank a = bank(name);
	banks.push_back(a);
}

void menu_helper::print_banks(vector<bank>& banks)
{
	for (int i = 0; i < banks.size(); i++)
	{
		string bank_name = banks[i].get_name();
		print_string(string_formatter::format("%d.%s", i, bank_name.c_str()));
		print_string();
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
	customer_account& customer_account = select_customer_account(bank);
	const double savings = customer_account.get_savings();
	print_string(string_formatter::format("Customer has: %f", savings));
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
	const vector<customer_account>& customer_accounts = bank.get_customer_accounts();
	for (int i = 0; i < customer_accounts.size(); i++)
	{
		const customer_account& customer_account = customer_accounts[i];
		print_string(string_formatter::format("%d.%s",
		                                      i,
		                                      customer_account.get_customer().get_customer_name().c_str()));
	}
}

void menu_helper::create_customer_account()
{
	bank& bank = select_bank();

	print_string("customer name:");
	bank.create_customer_account(read_string());
}
