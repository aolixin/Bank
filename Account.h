#pragma once
class SavingsAccount {
public:
	//�˻�
	int id;
	//����
	double balance;
	//������
	double rate;
	//����������
	int lastDate;
	//��Ϣ
	double accumulation;
	//���캯��
	SavingsAccount(int date, int id, double rate);
	//��������
	void record(int date, double amount);
	//����Ϣ
	double accumulate(int date);
	//���
	void deposit(int date, double amount);
	//ȡ��
	void withdraw(int date, double amount);
	//�ܽ���Ϣ
	void settle(int date);
	//չʾ��Ϣ
	void show()const;
	//��ñ���
	double getBalance();
};