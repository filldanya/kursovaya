#include <iostream>
#include "Broomstick.h"
Broomstick::Broomstick(int speed, std::string name)
{
	this->speed = speed;
	this->name = name;
}
std::string const Broomstick::get_name()
{
	return name;
}
int Broomstick::race(double dis)
{
	int time = 0;
	if (speed == 0)
	{
		return 0;
	}
	int tmp = dis;
	double tmp_d = 0;
	tmp /= 1000;
	tmp_d = tmp / 100.0;
	dis *= 1 - tmp_d;
	return time = dis / speed;
}