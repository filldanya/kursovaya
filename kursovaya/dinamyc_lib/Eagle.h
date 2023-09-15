#pragma once
#include <iostream>
#include "Air.h"
class Eagle : public Air
{
private:
	int speed = 0;
	std::string name;
public:
	Eagle(int speed, std::string name);
		std::string const get_name() override;
		int race(double dis) override;
};