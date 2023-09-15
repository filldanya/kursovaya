#include <iostream>
#include "Eagle.h"
Eagle::Eagle(int speed, std::string name)
{
	this->speed = speed;
	this->name = name;
}
std::string const Eagle::get_name()
{
	return name;
}
int Eagle::race(double dis)
{
	if (speed == 0)
	{
		return 0;
	}
	int time = 0;
	dis *= 0.94;
	return time = time = dis / speed;;
}