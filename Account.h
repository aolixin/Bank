#pragma once
#include "date.h"
#include<string>
using namespace std;

class SavingsAccount {
private:
	//账户
	string id;
	//本金
	double balance;
	//年利率
	double rate;
	//最后操作日期
	Date lastDate;
	//利息
	double accumulation;
	//
	static double total;
public:

	//构造函数
	SavingsAccount(Date date, string id, double rate);
	//操作本金
	void record(Date date, double amount,string target);
	//算利息
	double accumulate(Date date);
	//存款
	void deposit(Date date, double amount, string id);
	//取款
	void withdraw(Date date, double amount, string target);
	//总结利息
	void settle(Date date);
	//展示信息
	void show()const;
	//获得本金
	double getBalance();
	//返回总金额
	static double getTotal();
};