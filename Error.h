#pragma once
#include <exception>
#include <iostream>
#include <string>
#include<stdexcept>

#include "Account.h"
using namespace std;
class Error : public exception
{
private:
	string msg;
public:
	//���캯��
	Error(string msg)throw();
	//�״���
	const char* what() const throw();
};

class AccountException : public runtime_error
{
private:
	Account* account;
public:
	AccountException(string msg, Account* account);
	Account* getAccount();
};

