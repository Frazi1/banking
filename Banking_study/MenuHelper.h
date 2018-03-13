﻿#pragma once

#include "stdafx.h";
#include "PhysicalCustomer.h"

class menu_helper
{
private:
	vector<bank*>* banks_{};
	vector<customer*>* customers_{};
public:
	menu_helper(vector<bank*>* banks, vector<customer*>* customers);

	void process_input();
	//printing
	static void print_string(std::string str);
	static void print_string();
	static void print_menu();
	static void print_customers(bank* bank);
	customer_type select_customer_type() const;
	void print_banks();
	void print_bank_customer_accounts();

	//Manage account
	void create_customer_account();
	void add_bank();
	physical_customer* create_physical_customer();
	void create_customer();

	//Input
	static string read_string();
	static int read_int();
	static double read_double();
	static time_t read_date();
	static int select_int(string msg);
	static string select_string(string msg);
	static double select_double(string msg);


	//Money
	void put_customer_money();
	void transfer_money_to_other_customer();


	//Selection
	bank* select_bank(string display_message = "select bank\n");
	customer_account* select_customer_account(
		bank* bank, const string display_message = "select customer account\n") const;
	double select_amount() const;

	//Detetion
	void delete_bank();
	void delete_customer();
};
