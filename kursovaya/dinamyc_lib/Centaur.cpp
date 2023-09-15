#include <iostream>
#include "Centaur.h"
Centaur::Centaur(int speed, int rest, std::string name)
{
	this->speed = speed;
	this->rest = rest;
	this->name = name;
}
std::string const Centaur::get_name()
{
	return name;
}
int Centaur::race(double dis)
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
			time += 2;
		}
	}
	return time;
}