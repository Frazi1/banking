#pragma once

#include "stdafx.h";

class menu_helper
{
private:
	shared_ptr<vector<shared_ptr<bank>>> banks_{};
public:
	menu_helper(shared_ptr<vector<shared_ptr<bank>>> banks);

	void process_input();
	//printing
	static void print_string(std::string str);
	static void print_string();
	static void print_menu();
	static void print_customers(shared_ptr<bank> bank);
	void print_banks();
	void print_bank_customer_accounts();

	//Manage account
	void create_customer_account();
	void add_bank();

	//Input
	static string read_string();
	static int read_int();
	static double read_double();

	//Money
	void put_customer_money();
	void transfer_money_to_other_customer();


	//Selection
	shared_ptr<bank> select_bank(string display_message = "select bank\n");
	shared_ptr<customer_account> select_customer_account(
		shared_ptr<bank> bank, const string display_message = "select customer account\n") const;
	double select_amount() const;
};
