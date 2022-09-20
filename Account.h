#pragma once
#include "date.h"
#include<string>
#include "Accumulator.h"
#include<map>
using namespace std;

class AccountRecord;


//����
class Account {
private:
	//�˻�
	string id;
	//����
	double balance;
	//ȫ��Ǯ
	static double total;

	//��Ŀ��¼
	static multimap<Date, AccountRecord>recordMap;

public:
	Account(Date date, string id);
	void record(Date date, double amount, string desc);
	void error(string msg) const;
	string getId()const;
	double getBalance()const;
	void show()const;
	double static getTotal();
	//��Ǯ����
	virtual void deposit(Date date, double amount, string id) = 0;
	//ȡǮ����
	virtual void withdraw(Date date, double amount, string target) = 0;
	virtual void settle(Date date) = 0;
	//��ѯ����
	static void query(Date date1,Date date2);
};


class SavingsAccount:public Account
{
private:
	double rate;
	Accumulator acc;
public:

	//���캯��
	SavingsAccount(Date date, string id, double rate);
	//
	double getRate()const;
	//���
	void deposit(Date date, double amount, string id);
	//ȡ��
	void withdraw(Date date, double amount, string target);
	//�ܽ���Ϣ
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