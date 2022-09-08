#pragma once
class SavingsAccount {
public:
	//账户
	int id;
	//本金
	double balance;
	//年利率
	double rate;
	//最后操作日期
	int lastDate;
	//利息
	double accumulation;
	//构造函数
	SavingsAccount(int date, int id, double rate);
	//操作本金
	void record(int date, double amount);
	//算利息
	double accumulate(int date);
	//存款
	void deposit(int date, double amount);
	//取款
	void withdraw(int date, double amount);
	//总结利息
	void settle(int date);
	//展示信息
	void show()const;
	//获得本金
	double getBalance();
};