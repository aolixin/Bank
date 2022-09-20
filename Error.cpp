#include "Error.h"
#include "Account.h"
Error::Error(string msg)throw()
{
	this->msg = "Error:" + msg;
}

const char* Error::what() const throw()
{
	return msg.c_str();
}


AccountException::AccountException(string msg, Account* account) :runtime_error(msg)
{
	this->account = account;
}

Account* AccountException::getAccount()
{
	return account;
}