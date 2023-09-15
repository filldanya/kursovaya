#pragma once
#include <iostream>
#include "Ground.h"
class Camel : public Ground
{
private:
	int speed = 0;
	int rest = 0;
	std::string name;
public:
	Camel(int speed, int rest, std::string name);
	std::string const get_name() override;
	int race(double dis) override;
};