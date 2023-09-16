#pragma once
#include <iostream>
#include "Ground.h"
#ifdef DINAMLIBRACE_EXPORTS
#define MATHPOWERLIBRARY_API __declspec(dllexport)
#else
#define MATHPOWERLIBRARY_API __declspec(dllimport)
#endif
class All_terrain_boots : public Ground
{
private:
	int speed = 0;
	int rest = 0;
	std::string name;
public:
	MATHPOWERLIBRARY_API All_terrain_boots(int speed, int rest, std::string name);
	MATHPOWERLIBRARY_API std::string const get_name() override;
	MATHPOWERLIBRARY_API int race(double dis) override;
};