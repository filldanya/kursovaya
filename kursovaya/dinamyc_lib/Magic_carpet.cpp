#include <iostream>
#include "Magic_carpet.h"
Magic_carpet::Magic_carpet(int speed, std::string name)
{
	this->speed = speed;
	this->name = name;
}
std::string const Magic_carpet::get_name()
{
	return name;
}
int Magic_carpet::race(double dis)
{
	int time = 0;
	if (speed == 0)
	{
		return 0;
	}
	if (dis < 1000)
	{
		return time = dis / speed;

	}
	else if (dis >= 1000 && dis < 5000)
	{
		dis *= 0.97;
		return time = dis / speed;
	}
	else if (dis >= 5000 && dis < 10000)
	{
		dis *= 0.9;
		return time = dis / speed;
	}
	else
	{
		dis *= 0.95;
		return time = dis / speed;
	}
}