// Banking_study.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	const auto banks = new vector<bank*>();
	const auto customers = new vector<customer*>();
	menu_helper helper = menu_helper(banks, customers);
	while (true)
	{
		menu_helper::print_menu();
		try
		{
			helper.process_input();
		}
		catch (banking_exception e)
		{
			menu_helper::print_string(e.what());
		}
		catch (exception e)
		{
			menu_helper::print_string(e.what());
		}
	}
}
