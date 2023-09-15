#include <iostream>
#include "Camel.h"
Camel::Camel(int speed, int rest, std::string name)
{
	this->speed = speed;
	this->rest = rest;
	this->name = name;
}
std::string const Camel::get_name()
{
	return name;
}
int Camel::race(double dis)
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
			{

				if (a != 1)
				{
					if (i == 0)
					{
						time += 5;
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