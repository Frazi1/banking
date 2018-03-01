#pragma once
#include "Bank.h"

class menu_helper
{
public:
	static void print_menu();
	static void print_customers(bank& bank);
	static void print_banks(vector<bank>& banks);
	static void print_bank_customer_accounts(vector<bank>& banks);
	static void create_customer_account(vector<bank>& banks);
	static void add_bank(vector<bank>& banks);
	static void process_input(vector<bank>& banks);
	static std::string read_string();
	static int read_int();
	static void print_string(std::string str);
	static void print_string();
};
