#include "stdafx.h"
#include "MenuHelper.h"
#include <iostream>
#include "Bank.h"
#include "StringFormatter.h"
#include <iomanip>


using namespace std;


menu_helper::menu_helper(vector<bank*>* banks, vector<customer*>* customers) : banks_(banks), customers_(customers)
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
		create_customer_account_in_bank();
		break;
	case 3:
		put_customer_money();
		break;
	case 4:
		transfer_money_to_other_customer();
		break;
	case 5:
		print_banks();
		break;
	case 6:
		print_bank_customer_accounts();
		break;
	case 7:
		delete_bank();
		break;
	case 8:
		delete_customer();
		break;
	case 9:
		create_customer();
		break;
	case 10:
		print_all_customers();
		break;
	default: ;
	}
}

void menu_helper::print_menu()
{
	std::vector<string> items;
	items.push_back("1. Create bank");
	items.push_back("2. Create bank customer");
	items.push_back("3. Put money");
	items.push_back("4. Transfer money");
	items.push_back("5. Print banks");
	items.push_back("6. Print bank customers");
	items.push_back("7. Delete bank");
	items.push_back("8. Delete customer");
	items.push_back("9. Create cutomer");
	items.push_back("10. Print all customers");


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

tm menu_helper::read_date()
{
	tm date = {};
	const string input = select_string("Date:");
	istringstream ss(input);
	//ss.imbue(locale("en_US"));
	ss.imbue(locale());
	ss >> get_time(&date, "%d/%m/%Y");
	if (ss.fail())
		throw invalid_argument("date parse failed");

	return date;
}

int menu_helper::select_int(const string msg)
{
	print_string(msg);
	return read_int();
}

string menu_helper::select_string(const string msg)
{
	print_string(msg);
	return read_string();
}

double menu_helper::select_double(string msg)
{
	print_string(msg);
	return read_double();
}

void menu_helper::put_customer_money()
{
	bank* bank = select_bank();
	const customer_account* customer_account = select_customer_account(bank);
	const double amount = read_double();
	bank->put_money(customer_account->get_id(), amount);
}

void menu_helper::transfer_money_to_other_customer()
{
	bank* source_bank = select_bank("select source bank\n");
	customer_account* source_customer = select_customer_account(source_bank, "select source customer\n");

	bank* destination_bank = select_bank("select destination bank\n");
	customer_account* destination_customer = select_customer_account(
		destination_bank, "select destination customer\n");

	const double amount = select_amount();
	source_customer->transfer(destination_customer, amount);
}

bank* menu_helper::select_bank(const string display_message) const
{
	print_string(display_message);
	print_banks();
	bank* bank = banks_->at(read_int());
	return bank;
}

customer* menu_helper::select_customer() const
{
	print_all_customers();
	const int index = read_int();
	return customers_->at(index);
}

customer_account* menu_helper::select_customer_account(bank* bank, const string display_message) const
{
	print_string(display_message);
	print_bank_customers(bank);
	const int index = read_int();
	vector<customer_account*>& ca = bank->get_customer_accounts();
	customer_account* customer_account = ca.at(index);
	return customer_account;
}

double menu_helper::select_amount() const
{
	print_string("select amount\n");
	return read_double();
}

void menu_helper::delete_bank()
{
	bank* target = select_bank();
	banks_->erase(remove_if(banks_->begin(),
	                        banks_->end(),
	                        [target](bank* bank) { return bank == target; }),
	              banks_->end());
	delete target;
}

void menu_helper::delete_customer()
{
	bank* target_bank = select_bank();
	customer_account* target_customer = select_customer_account(target_bank);
	target_bank->delete_customer_account([&target_customer](customer_account* a) { return a == target_customer; });
}

void menu_helper::add_bank()
{
	print_string("define bank name");
	const string name = read_string();
	bank* a = new bank(0, 0.1f, name);
	banks_->push_back(a);
}

physical_customer* menu_helper::create_physical_customer()
{
	const string first_name = select_string("first_name");
	const string last_name = select_string("last name:");
	const int series = select_int("Passport series:");
	const int number = select_int("Passport number");
	const string registration_place = select_string("Registration place:");
	const tm registration_date = read_date();
	physical_customer* c = new physical_customer(first_name, last_name, number, series, registration_place,
	                                             registration_date);
	return c;
}

customer* menu_helper::create_juridic_customer()
{
	const string inn = select_string("inn");
	const string ogrnip = select_string("ogrnip");
	const tm registration_date = read_date();
	const string registration_place = select_string("registration place");
	const string hometown = select_string("hometown");
	const string organization_name = select_string("organization name");
	const string orgranization_type = select_string("ogranization type");
	juridic_customer* c = new juridic_customer(inn, ogrnip, registration_date, registration_place, hometown,
	                                           organization_name, orgranization_type);
	return c;
}

void menu_helper::create_customer()
{
	const customer_type type = select_customer_type();
	if (type == customer_type::physical)
		customers_->push_back(create_physical_customer());
	else if (type == customer_type::juridic)
		customers_->push_back(create_juridic_customer());
	else throw banking_exception("invalid customer type");
}

void menu_helper::print_banks() const
{
	for (int i = 0; i < banks_->size(); i++)
	{
		bank* bank = banks_->at(i);
		string bank_name = bank->get_name();
		print_string(string_formatter::format("%d.%s - has: %f",
		                                      i,
		                                      bank_name.c_str(),
		                                      bank->get_savings()));
	}
}

void menu_helper::print_bank_customer_accounts()
{
	bank* bank = select_bank();
	print_bank_customers(bank);
}

void menu_helper::print_string(const string str)
{
	std::cout << str << endl;
}

void menu_helper::print_string()
{
	std::cout << endl;
}


void menu_helper::print_bank_customers(bank* bank)
{
	auto customer_accounts = bank->get_customer_accounts();
	for (int i = 0; i < customer_accounts.size(); i++)
	{
		const customer_account* customer_account = customer_accounts.at(i);
		print_string(string_formatter::format("%d.%s - has: %f",
		                                      i,
		                                      customer_account->get_customer()->get_short_info().c_str(),
		                                      customer_account->get_savings()));
	}
}

void menu_helper::print_all_customers() const
{
	for (int i = 0; i < customers_->size(); i++)
	{
		const auto& c = customers_->at(i);
		print_string(string_formatter::format("%d. %s",
		                                      i,
		                                      c->get_short_info().c_str()));
	}
}

customer_type menu_helper::select_customer_type() const
{
	print_string("customer type: 1.physical, 2.juridic");
	return static_cast<customer_type>(read_int());
}

void menu_helper::create_customer_account_in_bank()
{
	bank* bank = select_bank();

	//const customer_type type = select_customer_type();

	//print_string("customer name:");
	//const string name = read_string();
	customer* customer = select_customer();
	bank->create_customer_account(customer);
}
