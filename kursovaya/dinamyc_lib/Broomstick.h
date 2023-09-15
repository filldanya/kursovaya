#pragma once
#include <iostream>
#include "Air.h"
class Broomstick : public Air
{
private:
	int speed;
	std::string name;
public:
	Broomstick(int speed, std::string name);
	std::string const get_name() override;
	int race(double dis) override;
};