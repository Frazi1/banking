#pragma once
#include "stdafx.h";
#include "CustomerAccount.h"

using namespace std;

class customer
{
public:
	virtual ~customer() = default;
	virtual string get_full_info() const = 0;
	virtual string get_short_info() const = 0;
	virtual customer_type get_customer_type() = 0;
};
