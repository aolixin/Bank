#pragma once
class Date {
private:
	int y, m, d;
	
public:int totalDays;
	Date(int y, int m, int d);
	Date(const Date& date);
	void getTotal();
	void show();
	int getMaxDay();
	//ÖØÔØ-ÔËËã·û
	int operator - (const Date& b);
};