#include "stdafx.h"
#include "BankingException.h"


BankingException::BankingException(const string message)
{
	_message = message;
}

BankingException::~BankingException()
{
}

string BankingException::GetMessage()
{
	return _message;
}
