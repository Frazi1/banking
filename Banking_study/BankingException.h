#pragma once
#include <exception>
#include <string>

using namespace std;
#pragma once
class BankingException : public exception
{
private:
	string _message;
public:
	BankingException(const string message);
	~BankingException();
	string GetMessage();
};


