#pragma once
#include <iostream>
#include "Ground.h"

class Centaur : public Ground
{
private:
	int speed;
	int rest;
	std::string name;
public:
	Centaur(int speed, int rest, std::string name);
		std::string const get_name() override;
		int race(double dis) override;
};