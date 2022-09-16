#pragma once
#include "date.h"
using namespace std;
class Accumulator {

	//本金
	double value;
	//总利息
	double sum;
public:
	//最后操作日期
	Date lastDate;
	Accumulator(Date date, double value);
	Accumulator();
	double getSum()const;
	// 改变本金，计算利息
	void change(Date date,double value);
	// 归零，不计算利息
	void reset(Date date, double value);
};