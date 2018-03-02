#pragma once
#include "Bank.h"

class menu_helper
{
private:
	vector<bank> banks_{};
public:
	menu_helper(vector<bank> banks);

	void process_input();
	//printing
	static void print_string(std::string str);
	static void print_string();
	static void print_menu();
	static void print_customers(bank& bank);
	static void print_banks(vector<bank>& banks);
	void print_bank_customer_accounts();
	void print_customer_money();
	void print_bank_money();

	//Manage account
	void create_customer_account();
	static void add_bank(vector<bank>& banks);

	//Input
	static string read_string();
	static int read_int();
	static double read_double();

	//Money
	void put_customer_money();
	void transfer_money_to_other_customer();


	//Selection
	bank& select_bank(string display_message = "select bank\n");
	customer_account& select_customer_account(bank& bank, string display_message = "select customer account\n") const;
	double select_amount() const;
};
