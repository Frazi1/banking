#include "stdafx.h"

juridic_customer_account::juridic_customer_account(const double savings,
                                                   juridic_customer* customer,
                                                   const long id,
                                                   bank* bank)
	: customer_account(id, savings, bank), customer_(customer)
{
}

customer* juridic_customer_account::get_customer() const
{
	return customer_;
}
