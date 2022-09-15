#pragma once
#include "date.h"
#include<string>
#include "Accumulator.h"
using namespace std;

//����
class Account {
private:
	//�˻�
	string id;
	//����
	double balance;
	//ȫ��Ǯ
	static double total;
public:
	//
	Account(Date date, string id);
	void record(Date date, double amount, string desc);
	void error(string msg) const;
	string getId()const;
	double getBalance()const;
	void show()const;
	double static getTotal();
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
	double getDebt()const;
	double getCredit()const;
	double getRate()const;
	double getFee()const;
};