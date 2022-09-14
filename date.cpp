#include "date.h"
#include<iostream>
#include <iomanip>
#include<sstream>
using namespace std;

namespace {//namespaceʹ����Ķ���ֻ�ڵ�ǰ�ļ�����Ч
//�洢ƽ����ĳ����1��֮ǰ�ж����죬Ϊ����getMaxDay������ʵ�֣���������һ��
	const int DAYS_BEFORE_MONTH[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
}
Date::Date(const Date& date)
{
	this->d = date.d;
	this->m = date.m;
	this->y = date.y;
	this->totalDays = date.totalDays;
}
int Date::operator-(const Date& b)
{
	return this->totalDays - b.totalDays;
}

void Date::getTotal()
{
	int p1 = 365 * (y - 1) + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400;
	int p2 = DAYS_BEFORE_MONTH[m - 1];
	int p3 = d;
	if (getMaxDay() == 366 && m > 2)p3++;
	this->totalDays = p1 + p2 + p3;
}

void Date::show()
{
	stringstream sstr;
	sstr << this->y << "-" << this->m << "-" << this->d;
	cout << setw(16) << setiosflags(ios::left) << sstr.str();
}

int Date::getMaxDay()
{
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)//ָ���Ƿ�Ϊ������ж�����
		return 366;
	else
		return 365;
}

Date::Date(int year, int month, int day) : y(year), m(month), d(day) {
	if (day <= 0 || day > getMaxDay()) {
		cout << "Invalid date: ";
		show();
		cout << endl;
		exit(1);  //������ֹ��ǰ�����ִ�У�����һ���������ظ�ϵͳ��ͨ����0��ʾ�����˳���1��ʾ�쳣�˳�
	}
	getTotal();
}
