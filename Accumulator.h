#pragma once
#include "date.h"
using namespace std;
class Accumulator {

	//����
	double value;
	//����Ϣ
	double sum;
public:
	//����������
	Date lastDate;
	Accumulator(Date date, double value);
	Accumulator();
	double getSum()const;
	// �ı䱾�𣬼�����Ϣ
	void change(Date date,double value);
	// ���㣬��������Ϣ
	void reset(Date date, double value);
};