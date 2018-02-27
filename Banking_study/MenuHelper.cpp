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

	for (const string item : items)
		print_string(item);
}

void menu_helper::print_customers(bank& bank)
{
	for (customer_account customer_account : bank.get_customer_accounts())
		print_string(customer_account.get_id());
}

void menu_helper::add_customer(vector<bank>& banks)
{
	print_string("Select bank");
	print_banks(banks);
	const int bank_id = read_int();

	print_string("Select customer");
	print_customers(banks[bank_id]);
	int customer_number = read_int();
}
