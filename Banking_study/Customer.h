#pragma once
#include "stdafx.h";

using namespace std;

class customer
{
private:
	string customer_name_{};

public:
	customer(string customer_name);
	
	string get_customer_name() const;

	void set_customer_name(const string& customer_name);
};
