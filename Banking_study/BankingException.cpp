#include "stdafx.h"
#include "BankingException.h"


banking_exception::banking_exception(const string message)
{
	_message = message;
}


banking_exception::~banking_exception()
{
}

string banking_exception::get_message() const
{
	return _message;
}

char const* banking_exception::what() const
{
	return _message.c_str();
}


