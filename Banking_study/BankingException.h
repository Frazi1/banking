#pragma once
#include <exception>
#include <string>

using namespace std;
#pragma once
class banking_exception : public exception
{
private:
	string _message;
public:
	banking_exception(const string message);
	~banking_exception();
	string get_message() const;

	char const* what() const override;
};


