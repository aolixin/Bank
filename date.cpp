#include "date.h"
#include<iostream>
#include <iomanip>
#include<sstream>
#include<cmath>
#include<vector>
#include "utils.h"
#include "Error.h" 
using namespace std;

namespace {//namespace使下面的定义只在当前文件中有效
//存储平年中某个月1日之前有多少天，为便于getMaxDay函数的实现，该数组多出一项
	const int DAYS_BEFORE_MONTH[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
}
Date::Date(const Date& date)
{
	this->d = date.d;
	this->m = date.m;
	this->y = date.y;
	this->totalDays = date.totalDays;
}
Date::Date()
{
	this->d = 0;
	this->m = 0;
	this->y = 0;
	this->totalDays = 0;
}
int Date::operator-(const Date& b)
{
	return this->totalDays - b.totalDays;
}/*
bool Date::operator<(const Date& b)
{
	if (this->totalDays - b.totalDays < 0)
		return true;
	else return false;
}
bool Date::operator>(const Date& b)
{
	if (this->totalDays - b.totalDays > 0)
		return true;
	else return false;
}*/


Date Date::read()
{
	string str;
	std::cin >> str;
	int y = 0, m=1, d=1;
	try {
		vector<int>vc = toInt(split(str, '/'));
		if (vc.size() != 3)
		{
			throw Error("Date format error");
		}
		y = vc[0];
		m = vc[1];
		d = vc[2];
	}
	catch (Error e)
	{
		cerr << e.what() << endl;
	}
	return Date(y, m, d);
}
void Date::getTotal()
{
	int p1 = 365 * (y - 1) + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400;
	int p2 = DAYS_BEFORE_MONTH[m - 1];
	int p3 = d;
	if (getMaxDay() == 366 && m > 2)p3++;
	this->totalDays = p1 + p2 + p3;
}

string Date::toString()const
{
	string str;
	for(int i=0;i<4;i++)
	{
		int t = pow(10, 3 - i);
		str.push_back((this->y /t%10 ) + '0');
	}
	str.push_back('-');
	if(this->m/10==0)str.push_back((this->m ) + '0');
	else
	{
		str.push_back((this->m /10) + '0');
		str.push_back((this->m % 10) + '0');
	}
	str.push_back('-'); 
	if (this->d / 10 == 0)str.push_back((this->d) + '0');
	else
	{
		str.push_back((this->d / 10) + '0');
		str.push_back((this->d % 10) + '0');
	}
	return str;
}

void Date::show()
{
	cout <<this->y<< "-" << this->m<<"-"<<this->d;
}

int Date::getMaxDay()
{
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)//指定是否为闰年的判断条件
		return 366;
	else
		return 365;
}

Date::Date(int year, int month, int day) : y(year), m(month), d(day) {
	if (day <= 0 || day > getMaxDay()) {
		cout << "Invalid date: ";
		toString();
		cout << endl;
		exit(1);  //用来中止当前程序的执行，并将一个整数返回给系统，通常，0表示正常退出，1表示异常退出
	}
	getTotal();
}

int Date::getYear()
{
	return y;
}
int Date::getMonth()
{
	return m;
}
int Date::getDay()
{
	return d;
}