#pragma once
#include<string>
using namespace std;
class Date {
private:
	int y, m, d;
	
public:int totalDays;
	Date(int y, int m, int d);
	Date(const Date& date);
	void getTotal();
	string show();
	int getMaxDay();
	//ÖØÔØ-ÔËËã·û
	int operator - (const Date& b);
	int getY();
	int getM();
	int getD();
};