#pragma once
#include "stdafx.h"
#include "Passport.h"

class physical_customer : public customer
{
private:
	passport* passport_{};
public:

	explicit physical_customer(passport* passport)
		: passport_(passport)
	{
	}
};
