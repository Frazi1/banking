// Banking_study.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Bank.h"
#include "MenuHelper.h"


int main()
{
	vector<bank> banks;
	while (true)
	{
		menu_helper::print_menu();
		menu_helper::process_input(banks);
	}
}


