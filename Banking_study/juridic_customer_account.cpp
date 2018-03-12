#include "stdafx.h"

juridic_customer_account::juridic_customer_account(const double savings,
                                                   const customer customer,
                                                   const long id,
                                                   const shared_ptr<bank> bank)
	: customer_account(savings, customer, id, bank)
{
}
