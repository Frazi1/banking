#pragma once
#include "stdafx.h";

using namespace std;

class customer
{
private:
	string customer_name_{};

public:
	customer(const string& customer_name);
	
	string get_customer_name();

	void set_customer_name(const string& customer_name);
};
