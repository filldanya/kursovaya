#pragma once
#include <iostream>
#include "Vehicle.h"
class Ground : public Vehicle
{
public:
	std::string const get_name() override;
	int race(double dis) override;
};