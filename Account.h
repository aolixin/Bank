#pragma once
#include "date.h"
#include<string>
using namespace std;

class SavingsAccount {
private:
	//�˻�
	string id;
	//����
	double balance;
	//������
	double rate;
	//����������
	Date lastDate;
	//��Ϣ
	double accumulation;
	//
	static double total;
public:

	//���캯��
	SavingsAccount(Date date, string id, double rate);
	//��������
	void record(Date date, double amount,string target);
	//����Ϣ
	double accumulate(Date date);
	//���
	void deposit(Date date, double amount, string id);
	//ȡ��
	void withdraw(Date date, double amount, string target);
	//�ܽ���Ϣ
	void settle(Date date);
	//չʾ��Ϣ
	void show()const;
	//��ñ���
	double getBalance();
	//�����ܽ��
	static double getTotal();
};