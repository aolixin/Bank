//account.cpp
#include "Account.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include "date.h"
#include<map>
using namespace std;

/*-------------------------------------account类函数--------------------------------------------*/

//静态变量赋值
double Account::total = 0;
multimap<Date, AccountRecord>Account::recordMap;
//构造函数
Account::Account(Date date, string id)
{
	this->id = id;
	this->balance = 0.0f;
	cout << setw(16) << setiosflags(ios::left) << date.toString() << "#" << this->getId() << " created" << endl;
}

void Account::record(Date date, double amount, string desc)
{
	amount = floor(amount * 100 + 0.5) / 100;
	this->balance += amount;
	total += amount;
	//创建账目
	AccountRecord accountrecord(date, this, amount, balance, desc);
	//插入账目记录
	recordMap.insert(std::make_pair(date, accountrecord));

	cout << setw(16) << setiosflags(ios::left) << date.toString()
		<< "#" << setw(15) << this->getId()
		<< setw(8) << setiosflags(ios::left) << amount
		<< setw(8) << setiosflags(ios::left) << this->getBalance() << desc << endl;

}

void Account::query(Date date1, Date date2)
{
	for (auto i = recordMap.begin(); i != recordMap.end(); i++)
	{
		if (date1 < i->first && date2>i->first)
		{
			cout << setw(16) << setiosflags(ios::left) << i->first.toString()
				<< "#" << setw(15) << i->second.getAccount()->getId()
				<< setw(8) << setiosflags(ios::left) << i->second.getAmount()
				<< setw(8) << setiosflags(ios::left) << i->second.getBalance() << i->second.getDesc() << endl;
		}
	}
}

// 展示
void Account::show() const
{
	cout << setw(16) << this->id << "Balance: " << this->getBalance();
}
// 报错
void Account::error(string msg)const
{
	cout << "Error: " << msg << endl;
}

string Account::getId()const
{
	return id;
}
double Account::getBalance() const
{
	return balance;
}
double Account::getTotal()
{
	return total;
}

/*-------------------------------------account类函数--------------------------------------------*/

/*----------------------------------SavingsAccount类函数----------------------------------------*/

//构造函数
SavingsAccount::SavingsAccount(Date date, string id, double rate):Account(date,id),acc(date, 0)
{
	this->rate = rate;
}

//存款
void SavingsAccount::deposit(Date date, double amount, string desc)
{
	record(date, amount, desc);
	acc.change(date, this->getBalance());
}
//取款
void SavingsAccount::withdraw(Date date, double amount, string target)
{
	record(date, -amount, target);
	acc.change(date, this->getBalance());
}
double SavingsAccount::getRate()const
{
	return rate;
}

void SavingsAccount::settle(Date date)
{
	acc.change(date, this->getBalance());
	int y = acc.lastDate.getYear();
	int m = acc.lastDate.getMonth();
	int d = acc.lastDate.getDay();
	double temp = acc.getSum()*rate/Date(y-1,m,d).getMaxDay();
	acc.reset(date, this->getBalance());
	record(date, temp, "interest");
}

/*----------------------------------SavingsAccount类函数----------------------------------------*/

/*-----------------------------------CreditAccount类函数----------------------------------------*/

//构造函数
CreditAccount::CreditAccount(Date date, string id, double credit, double rate, double fee) :Account(date, id)
{
	acc = Accumulator(date, 0);
	this->credit = credit;
	this->rate = rate;
	this->fee = fee;
}

//取款函数
void CreditAccount::withdraw(Date date, double amount, string decs)
{
	//判断是否超过信用额度
	if (this->getBalance() < -credit)
	{
		error("please repay the credit"); 
		return;
	}

	record(date,-amount,decs);
	acc.change(date, this->getBalance());
}void CreditAccount::deposit(Date date, double amount, string decs)
{
	record(date, amount, decs);
	acc.change(date, this->getBalance());
}
void CreditAccount::settle(Date date)
{
	if (date.getMonth() == 1 && date.getDay() == 1)
	{
		record(date, -fee, "annual fee");
	}
	acc.change(date, this->getBalance());
	double temp = acc.getSum()*rate;
	acc.reset(date, this->getBalance());

	if(temp<0)
	record(date, temp, "interest");
}

void  CreditAccount::show()
{
	if (this->getBalance() < 0)
		cout << setw(16) << this->getId() << "Balance: " << setw(7) << this->getBalance() << "Available credit:" << credit + this->getBalance();
	else
		cout << setw(16) << this->getId() << "Balance: " << setw(7) << this->getBalance() << "Available credit:" << credit
		;
}

/*-----------------------------------CreditAccount类函数----------------------------------------*/



/*-----------------------------------AccountRecord类函数----------------------------------------*/

AccountRecord::AccountRecord(Date date, Account* account,double amount ,double balance, string desc):date(date),amount(amount),balance(balance),desc(desc),account(account)
{}

const Account* AccountRecord::getAccount()const
{
	return account;
}

double AccountRecord::getAmount()const
{
	return amount;
}

double AccountRecord::getBalance()const
{
	return balance;
}
string AccountRecord::getDesc()const
{
	return desc;
}
/*-----------------------------------AccountRecord类函数----------------------------------------*/