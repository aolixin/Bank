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
	string toString();
	void show();
	int getMaxDay();
	//ÖØÔØ-ÔËËã·û
	int operator - (const Date& b);
	int getYear();
	int getMonth();
	int getDay();
};