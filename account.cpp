//account.cpp
#include "Account.h"
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

//double SavingsAccount::total = 0;

//SavingsAccount类相关成员函数的实现
SavingsAccount::SavingsAccount(int date, int id, double rate)
: id(id), balance(0), rate(rate), lastDate(date), accumulation(0) {
	//cout << date << "\t#" << id << " is created" << endl;
	cout << setw(8) << setiosflags(ios::left) << date << "#" << this->id << " is created" << endl;
}

void SavingsAccount::record(Date date, double amount, string target) {
	accumulation += accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100;	//保留两位小数
	balance += amount;
	//加到总金额
	total += amount;
	date.show();
	cout << "#" << setw(15) << setiosflags(ios::left) << id
		<< setw(8) << amount
		<< setw(8) << balance << target << endl;
}

void SavingsAccount::deposit(Date date, double amount, string target) {
	record(date, amount, target);
}

void SavingsAccount::withdraw(Date date, double amount, string target)
{
	record(date, -amount, target);
}

void SavingsAccount::settle(int date) {
	double interest = accumulate(date) + accumulation ;	//计算年息
	if (interest != 0)
		record(date, interest);
	accumulation = 0;
}

void SavingsAccount::show() const {
	cout << setiosflags(ios::left) << "#" << setw(15) << this->id << "Balance: " << this->balance;
}

double SavingsAccount::getBalance()
{
	return balance;
}

double SavingsAccount::accumulate(int date) {
	return this->balance* (date - this->lastDate)* rate / 365;
}
