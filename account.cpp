//account.cpp
#include "Account.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include "date.h"
using namespace std;

double SavingsAccount::total = 0;

//SavingsAccount类相关成员函数的实现
SavingsAccount::SavingsAccount(Date date, string id, double rate) :lastDate(date), id(id),
rate(rate), accumulation(0), balance(0)
{
	this->lastDate.show();
	cout << "#" << id << " created" << endl;

}

void SavingsAccount::record(Date date, double amount,string target) {
	accumulation += accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100;	//保留两位小数
	balance += amount;
	//加到总金额
	total += amount;
	date.show();
	cout << "#" << setw(15) << setiosflags(ios::left) <<id 
		<< setw(8) << amount
		<< setw(8) << balance  << target << endl;
}

void SavingsAccount::deposit(Date date, double amount, string target) {
	record(date, amount,target);
}

void SavingsAccount::withdraw(Date date, double amount, string target)
{
	record(date,-amount,target);
}

void SavingsAccount::settle(Date date)
{
	double temp = accumulate(date);
	temp = floor(temp * 100 + 0.5) / 100;
	this->accumulation += temp;
	this->lastDate = date;
	double amount = this->accumulation;
	amount = floor(amount * 100 + 0.5) / 100;
	this->accumulation = 0;
	record(date, amount, "interest");
}

void SavingsAccount::show() const {
	cout << setiosflags(ios::left) << "#" << setw(15) << this->id << "Balance: " << this->balance;
}

double SavingsAccount::getBalance()
{
	return balance;
}

double SavingsAccount::accumulate(Date date) {
	return this->balance * double(date - this->lastDate) * rate / 365;
}

double SavingsAccount::getTotal()
{
	return SavingsAccount::total;
}
