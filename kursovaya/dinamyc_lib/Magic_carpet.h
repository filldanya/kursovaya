#pragma once
#include <iostream>
#include "Air.h"
class Magic_carpet : public Air
{
private:
	int speed = 0;
	std::string name;
public:
	Magic_carpet(int speed, std::string name);
		std::string const get_name() override;
		int race(double dis) override;
};