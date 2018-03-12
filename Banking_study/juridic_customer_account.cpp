#include "stdafx.h"

juridic_customer_account::juridic_customer_account(const double savings,
                                                   const customer customer,
                                                   const long id,
                                                   bank* bank)
	: customer_account(savings, customer, id, bank)
{
}
