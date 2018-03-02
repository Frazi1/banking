// Banking_study.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Bank.h"
#include "MenuHelper.h"


int main()
{
	const vector<bank> banks;
	menu_helper helper =  menu_helper(banks);
	while (true)
	{
		menu_helper::print_menu();
		helper.process_input();
	}
}


