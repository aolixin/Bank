#pragma once
#include "date.h"
#include<string>
#include "Accumulator.h"
#include<map>
using namespace std;

class AccountRecord;


//父类
class Account {
private:
	//账户
	string id;
	//本金
	double balance;
	//全部钱
	static double total;

	//账目记录
	static multimap<Date, AccountRecord>recordMap;

public:
	Account(Date date, string id);
	void record(Date date, double amount, string desc);
	void error(string msg) const;
	string getId()const;
	double getBalance()const;
	void show()const;
	double static getTotal();
	//存钱函数
	virtual void deposit(Date date, double amount, string id) = 0;
	//取钱函数
	virtual void withdraw(Date date, double amount, string target) = 0;
	virtual void settle(Date date) = 0;
	//查询函数
	static void query(Date date1,Date date2);
};


class SavingsAccount:public Account
{
private:
	double rate;
	Accumulator acc;
public:

	//构造函数
	SavingsAccount(Date date, string id, double rate);
	//
	double getRate()const;
	//存款
	void deposit(Date date, double amount, string id);
	//取款
	void withdraw(Date date, double amount, string target);
	//总结利息
	void settle(Date date);
};


class CreditAccount :public Account
{
private:
	Accumulator acc;
	double credit;
	double rate;
	double fee;
public:
	CreditAccount(Date date, string id, double credit, double rate, double fee);
	void withdraw(Date date, double amount, string target);
	void deposit(Date date, double amount, string target);
	void show();
	void settle(Date date);
};

class AccountRecord
{
private:
	Date date;
	const Account* account;
	double amount;
	double balance;
	string desc;
public:
	AccountRecord(Date date, Account* account,double amount, double balance, string desc);
	const Account* getAccount()const;
	double getAmount()const;
	double getBalance()const;
	string getDesc()const;
};