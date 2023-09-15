#include <iostream>
#include "All_terrain_boots.h"
All_terrain_boots::All_terrain_boots(int speed, int rest, std::string name)
{
	this->speed = speed;
	this->rest = rest;
	this->name = name;
}
std::string const  All_terrain_boots::get_name()
{
	return name;
}
int All_terrain_boots::race(double dis)
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
				time += 10;
				return time;
			}
			{

				if (a != 1)
				{
					if (i == 0)
					{
						time += 10;
					}
					else
					{
						time += 5;
					}
				}
			}
		}
	}
	return time;
}