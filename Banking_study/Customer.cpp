#include "stdafx.h"
#include "Customer.h"

customer::customer(const string customer_name):
	customer_name_(customer_name)
{
}

void customer::set_customer_name(const string& customer_name)
{
	customer_name_ = customer_name;
}

string customer::get_customer_name() const
{
	return customer_name_;
}
