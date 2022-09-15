#include "date.h"
#include "Accumulator.h"
#include <cmath>
//���캯��
Accumulator::Accumulator(Date date, double value) :lastDate(date), value(value),sum(0) {}

double Accumulator::getSum()const
{
	return sum;
}

void Accumulator::change(Date date, double value)
{
	double temp = this->value * (date - this->lastDate);
	temp = floor(temp * 100 + 0.5) / 100;
	sum += temp;
	this->lastDate = date;
	this->value = value;
}

void Accumulator::reset(Date date, double value)
{
	lastDate = date;
	this->value = value;
	this->sum = 0;
}
