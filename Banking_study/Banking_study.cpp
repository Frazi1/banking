// Banking_study.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	const vector<bank> banks;
	menu_helper helper =  menu_helper(banks);
	while (true)
	{
		menu_helper::print_menu();
		try
		{
			helper.process_input();
		}
		catch(banking_exception e)
		{
			menu_helper::print_string(e.what());
		}
		catch(exception e)
		{
			menu_helper::print_string(e.what());
		}
	}
}


