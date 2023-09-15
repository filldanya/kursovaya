#include <iostream>
#include "Fast_camel.h"
Fast_camel::Fast_camel(int speed, int rest, std::string name)
{
	this->speed = speed;
	this->rest = rest;
	this->name = name;
}
std::string const Fast_camel::get_name()
{
	return name;
}
int Fast_camel::race(double dis)
{
	int time = 0;
	if (speed == 0)
	{
		return 0;
	}
	time = dis / speed;
	if (time > rest)
	{
		int a = time / rest;
		if (time % rest != 0)
		{
			a++;
		}
		for (int i = 0; i < a - 1; i++)
		{
			if (a == 1)
			{
				time += 5;
				return time;
			}
			if (a == 2)
			{
				if (i == 0)
				{
					time += 5;
				}
				else
				{
					time += 6, 5;
				}
			}
			{

				if (a >= 3)
				{
					if (i == 0)
					{
						time += 5;
					}
					else if (i == 1)
					{
						time += 6, 5;
					}
					else
					{
						time += 8;
					}
				}
			}
		}
	}
	return time;
}