#pragma once
#include <iostream>
class Vehicle
{
public:
	virtual const std::string get_name();
	virtual int race(double dis);
};