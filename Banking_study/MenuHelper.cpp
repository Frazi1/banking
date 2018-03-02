#include "stdafx.h"
#include "MenuHelper.h"
#include <iostream>
#include "Bank.h"
#include "StringFormatter.h"

using namespace std;


void menu_helper::process_input(vector<bank>& banks)
{
	int input;
	cin >> input;

	switch (input)
	{
	case 1:
		add_bank(banks);
		break;
	case 2:
		print_banks(banks);
		break;
	case 3:
		create_customer_account(banks);
		break;
	case 4:
		print_bank_customer_accounts(banks);
		break;
	}
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

void menu_helper::print_bank_customer_accounts(vector<bank>& banks)
{
	print_string("select bank\n");
	print_banks(banks);
	int bank_id = read_int();
	bank& bank = banks[bank_id];
	print_customers(bank);
}

void menu_helper::print_string(const string str)
{
	std::cout << str << endl;
}

void menu_helper::print_string()
{
	std::cout << endl;
}

void menu_helper::print_menu()
{
	std::vector<string> items;
	items.push_back("1. Add bank");
	items.push_back("2. Print banks");
	items.push_back("3. Create bank customer");
	items.push_back("4. Print bank customers");

	for (const string item : items)
		print_string(item);
}

void menu_helper::print_customers(bank& bank)
{
	//print_string("Select bank");
	//bank bank = banks[read_int()];
	const vector<customer_account>& customer_accounts = bank.get_customer_accounts();
	for (int i = 0; i < customer_accounts.size(); i++)
	{
		const customer_account& customer_account = customer_accounts[i];
		print_string(string_formatter::format("%d.%s",
		                                      i,
		                                      customer_account.get_customer().get_customer_name().c_str()));
	}
}

void menu_helper::create_customer_account(vector<bank>& banks)
{
	print_string("Select bank\n");
	print_banks(banks);
	bank& bank = banks[read_int()];

	print_string("customer name:");
	bank.create_customer_account(read_string());
}
