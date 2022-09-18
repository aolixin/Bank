#pragma once
#include<string>
#include<iostream>
using namespace std;
class Date {
private:
	int y, m, d;

public:int totalDays;
	  Date(int y, int m, int d);
	  Date();
	  Date(const Date& date);
	  void getTotal();
	  string toString()const;
	  void show();
	  int getMaxDay();
	  //ÖØÔØ-ÔËËã·û
	  int operator - (const Date& b);
	  bool operator < (const Date& b) const
	  {
		  if (this->totalDays - b.totalDays < 0)
			  return true;
		  else return false;
	  }
	  bool operator > (const Date& b) const
	  {
		  if (this->totalDays - b.totalDays > 0)
			  return true;
		  else return false;
	  }

	  static Date read();
	  int getYear();
	  int getMonth();
	  int getDay();
};