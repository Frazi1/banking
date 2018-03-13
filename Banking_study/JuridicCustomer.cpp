#include "stdafx.h"
#include "JuridicCustomer.h"

juridic_customer::juridic_customer(const string inn,
                                   const string ogrnip, const time_t registration_date,
                                   const string registration_place,
                                   const string hometown,
                                   const string organisation_name,
                                   const string organisation_type)
	: inn_(inn),
	  ogrnip_(ogrnip),
	  registration_date_(registration_date),
	  registration_place_(registration_place),
	  hometown_(hometown),
	  organisation_name_(organisation_name),
	  organisation_type_(organisation_type)
{
}
